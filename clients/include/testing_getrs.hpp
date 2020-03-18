/* ************************************************************************
 * Copyright 2016-2020 Advanced Micro Devices, Inc.
 *
 * ************************************************************************ */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "cblas_interface.h"
#include "flops.h"
#include "hipblas.hpp"
#include "norm.h"
#include "unit.h"
#include "utility.h"

using namespace std;

template <typename T>
hipblasStatus_t testing_getrs(Arguments argus)
{
    int N   = argus.N;
    int lda = argus.lda;
    int ldb = argus.ldb;

    int A_size    = lda * N;
    int B_size    = ldb * 1;
    int Ipiv_size = N;

    hipblasStatus_t status = HIPBLAS_STATUS_SUCCESS;

    // Check to prevent memory allocation error
    if(N < 0 || lda < N || ldb < N)
    {
        return HIPBLAS_STATUS_INVALID_VALUE;
    }

    // Naming: dK is in GPU (device) memory. hK is in CPU (host) memory
    host_vector<T>   hA(A_size);
    host_vector<T>   hX(B_size);
    host_vector<T>   hB(B_size);
    host_vector<T>   hB1(B_size);
    host_vector<int> hIpiv(Ipiv_size);
    host_vector<int> hIpiv1(Ipiv_size);

    device_vector<T>   dA(A_size);
    device_vector<T>   dB(B_size);
    device_vector<int> dIpiv(Ipiv_size);

    double gpu_time_used, cpu_time_used;
    double hipblasGflops, cblas_gflops;
    double rocblas_error;

    hipblasHandle_t handle;
    hipblasCreate(&handle);

    // Initial hA, hB, hX on CPU
    srand(1);
    hipblas_init<T>(hA, N, N, lda);
    hipblas_init<T>(hX, N, 1, ldb);

    // Calculate hB = hA*hX;
    hipblasOperation_t op = HIPBLAS_OP_N;
    cblas_gemm<T>(op, op, N, 1, N, 1, hA.data(), lda, hX.data(), ldb, 0, hB.data(), ldb);

    // Copy data from CPU to device
    CHECK_HIP_ERROR(hipMemcpy(dA, hA.data(), A_size * sizeof(T), hipMemcpyHostToDevice));
    CHECK_HIP_ERROR(hipMemcpy(dB, hB.data(), B_size * sizeof(T), hipMemcpyHostToDevice));
    CHECK_HIP_ERROR(hipMemset(dIpiv, 0, Ipiv_size * sizeof(int)));

    /* =====================================================================
           HIPBLAS
    =================================================================== */

    status = hipblasGetrs<T>(handle, op, N, 1, dA, lda, dIpiv, dB, ldb);

    // copy output from device to CPU
    CHECK_HIP_ERROR(hipMemcpy(hB1.data(), dB, B_size * sizeof(T), hipMemcpyDeviceToHost));
    CHECK_HIP_ERROR(
        hipMemcpy(hIpiv1.data(), dIpiv, Ipiv_size * sizeof(int), hipMemcpyDeviceToHost));

    if(argus.unit_check)
    {
        /* =====================================================================
           CPU LAPACK
        =================================================================== */

        cblas_getrs('N', N, 1, hA.data(), lda, hIpiv.data(), hB.data(), ldb);

        if(argus.unit_check)
        {
            unit_check_general<T>(N, 1, ldb, hB.data(), hB1.data());
        }
    }

    hipblasDestroy(handle);
    return HIPBLAS_STATUS_SUCCESS;
}
