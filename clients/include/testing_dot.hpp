/* ************************************************************************
 * Copyright 2016-2021 Advanced Micro Devices, Inc.
 *
 * ************************************************************************ */

#include <stdio.h>
#include <stdlib.h>
#include <vector>

#include "testing_common.hpp"

using namespace std;

/* ============================================================================================ */

template <typename T, bool CONJ = false>
hipblasStatus_t testing_dot(const Arguments& argus)
{
    bool FORTRAN      = argus.fortran;
    auto hipblasDotFn = FORTRAN ? (CONJ ? hipblasDotc<T, true> : hipblasDot<T, true>)
                                : (CONJ ? hipblasDotc<T, false> : hipblasDot<T, false>);

    int N    = argus.N;
    int incx = argus.incx;
    int incy = argus.incy;

    // argument sanity check, quick return if input parameters are invalid before allocating invalid
    // memory
    if(N < 0 || incx < 0 || incy < 0)
    {
        return HIPBLAS_STATUS_INVALID_VALUE;
    }

    int sizeX = N * incx;
    int sizeY = N * incy;

    // Naming: dX is in GPU (device) memory. hK is in CPU (host) memory, plz follow this practice
    host_vector<T> hx(sizeX);
    host_vector<T> hy(sizeY);

    T                cpu_result, h_hipblas_result_1, h_hipblas_result_2;
    device_vector<T> dx(sizeX);
    device_vector<T> dy(sizeY);
    device_vector<T> d_hipblas_result(1);

    double gpu_time_used, hipblas_error_host, hipblas_error_device;

    hipblasLocalHandle handle(argus);

    // Initial Data on CPU
    srand(1);
    hipblas_init_alternating_sign<T>(hx, 1, N, incx);
    hipblas_init<T>(hy, 1, N, incy);

    // copy data from CPU to device, does not work for incx != 1
    CHECK_HIP_ERROR(hipMemcpy(dx, hx.data(), sizeof(T) * sizeX, hipMemcpyHostToDevice));
    CHECK_HIP_ERROR(hipMemcpy(dy, hy.data(), sizeof(T) * sizeY, hipMemcpyHostToDevice));

    /* =====================================================================
         HIPBLAS
    =================================================================== */
    // hipblasDot accept both dev/host pointer for the scalar
    CHECK_HIPBLAS_ERROR(hipblasSetPointerMode(handle, HIPBLAS_POINTER_MODE_DEVICE));
    CHECK_HIPBLAS_ERROR((hipblasDotFn)(handle, N, dx, incx, dy, incy, d_hipblas_result));

    CHECK_HIPBLAS_ERROR(hipblasSetPointerMode(handle, HIPBLAS_POINTER_MODE_HOST));
    CHECK_HIPBLAS_ERROR((hipblasDotFn)(handle, N, dx, incx, dy, incy, &h_hipblas_result_1));

    CHECK_HIP_ERROR(
        hipMemcpy(&h_hipblas_result_2, d_hipblas_result, sizeof(T), hipMemcpyDeviceToHost));

    if(argus.unit_check || argus.norm_check)
    {
        /* =====================================================================
                    CPU BLAS
        =================================================================== */
        (CONJ ? cblas_dotc<T> : cblas_dot<T>)(N, hx.data(), incx, hy.data(), incy, &cpu_result);

        if(argus.unit_check)
        {
            unit_check_general<T>(1, 1, 1, &cpu_result, &h_hipblas_result_1);
            unit_check_general<T>(1, 1, 1, &cpu_result, &h_hipblas_result_2);
        }
        if(argus.norm_check)
        {
            hipblas_error_host
                = norm_check_general<T>('F', 1, 1, 1, &cpu_result, &h_hipblas_result_1);
            hipblas_error_device
                = norm_check_general<T>('F', 1, 1, 1, &cpu_result, &h_hipblas_result_2);
        }

    } // end of if unit/norm check

    if(argus.timing)
    {
        hipStream_t stream;
        CHECK_HIPBLAS_ERROR(hipblasGetStream(handle, &stream));
        CHECK_HIPBLAS_ERROR(hipblasSetPointerMode(handle, HIPBLAS_POINTER_MODE_DEVICE));

        int runs = argus.cold_iters + argus.iters;
        for(int iter = 0; iter < runs; iter++)
        {
            if(iter == argus.cold_iters)
                gpu_time_used = get_time_us_sync(stream);

            CHECK_HIPBLAS_ERROR((hipblasDotFn)(handle, N, dx, incx, dy, incy, d_hipblas_result));
        }
        gpu_time_used = get_time_us_sync(stream) - gpu_time_used;

        ArgumentModel<e_N, e_incx, e_incy>{}.log_args<T>(std::cout,
                                                         argus,
                                                         gpu_time_used,
                                                         dot_gflop_count<CONJ, T>(N),
                                                         dot_gbyte_count<T>(N),
                                                         hipblas_error_host,
                                                         hipblas_error_device);
    }

    return HIPBLAS_STATUS_SUCCESS;
}

template <typename T>
hipblasStatus_t testing_dotc(const Arguments& argus)
{
    return testing_dot<T, true>(argus);
}
