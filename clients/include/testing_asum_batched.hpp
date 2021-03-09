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

template <typename T>
hipblasStatus_t testing_asum_batched(const Arguments& argus)
{
    using Tr = real_t<T>;

    int N           = argus.N;
    int incx        = argus.incx;
    int batch_count = argus.batch_count;

    hipblasStatus_t status_1 = HIPBLAS_STATUS_SUCCESS;
    hipblasStatus_t status_2 = HIPBLAS_STATUS_SUCCESS;
    hipblasStatus_t status_3 = HIPBLAS_STATUS_SUCCESS;
    hipblasStatus_t status_4 = HIPBLAS_STATUS_SUCCESS;

    // check to prevent undefined memory allocation error
    if(N < 0 || incx < 0 || batch_count < 0)
    {
        return HIPBLAS_STATUS_INVALID_VALUE;
    }
    if(batch_count == 0)
    {
        return HIPBLAS_STATUS_SUCCESS;
    }

    int sizeX = N * incx;

    double gpu_time_used, hipblas_error_host, hipblas_error_device;

    hipblasHandle_t handle;
    hipblasCreate(&handle);

    // Naming: dX is in GPU (device) memory. hK is in CPU (host) memory, plz follow this practice
    host_vector<T>  hx_array[batch_count];
    host_vector<Tr> h_hipblas_result_host(batch_count);
    host_vector<Tr> h_hipblas_result_device(batch_count);
    host_vector<Tr> h_cpu_result(batch_count);

    device_batch_vector<T>  bx_array(batch_count, sizeX);
    device_vector<T*, 0, T> dx_array(batch_count);
    device_vector<Tr>       d_hipblas_result(batch_count);

    // Initial Data on CPU
    srand(1);
    for(int b = 0; b < batch_count; b++)
    {
        hx_array[b] = host_vector<T>(sizeX);

        srand(1);
        hipblas_init<T>(hx_array[b], 1, N, incx);

        CHECK_HIP_ERROR(
            hipMemcpy(bx_array[b], hx_array[b], sizeof(T) * sizeX, hipMemcpyHostToDevice));
    }
    CHECK_HIP_ERROR(hipMemcpy(dx_array, bx_array, sizeof(T*) * batch_count, hipMemcpyHostToDevice));

    /* =====================================================================
         HIPBLAS
    =================================================================== */
    // hipblasAsum accept both dev/host pointer for the scalar
    status_1 = hipblasSetPointerMode(handle, HIPBLAS_POINTER_MODE_DEVICE);
    status_2 = hipblasAsumBatched<T, Tr>(handle, N, dx_array, incx, batch_count, d_hipblas_result);

    status_3 = hipblasSetPointerMode(handle, HIPBLAS_POINTER_MODE_HOST);
    status_4
        = hipblasAsumBatched<T, Tr>(handle, N, dx_array, incx, batch_count, h_hipblas_result_host);

    if((status_1 != HIPBLAS_STATUS_SUCCESS)
       || (status_2 != HIPBLAS_STATUS_SUCCESS || (status_3 != HIPBLAS_STATUS_SUCCESS)
           || (status_4 != HIPBLAS_STATUS_SUCCESS)))
    {
        hipblasDestroy(handle);
        if(status_1 != HIPBLAS_STATUS_SUCCESS)
            return status_1;
        if(status_2 != HIPBLAS_STATUS_SUCCESS)
            return status_2;
        if(status_3 != HIPBLAS_STATUS_SUCCESS)
            return status_3;
        if(status_4 != HIPBLAS_STATUS_SUCCESS)
            return status_4;
    }

    CHECK_HIP_ERROR(hipMemcpy(h_hipblas_result_device,
                              d_hipblas_result,
                              sizeof(Tr) * batch_count,
                              hipMemcpyDeviceToHost));

    if(argus.unit_check || argus.norm_check)
    {
        /* =====================================================================
                    CPU BLAS
        =================================================================== */
        for(int b = 0; b < batch_count; b++)
        {
            cblas_asum<T, Tr>(N, hx_array[b], incx, &(h_cpu_result[b]));
        }

        if(argus.unit_check)
        {
            unit_check_general<Tr>(1, batch_count, 1, h_cpu_result, h_hipblas_result_host);
            unit_check_general<Tr>(1, batch_count, 1, h_cpu_result, h_hipblas_result_device);
        }
        if(argus.norm_check)
        {
            hipblas_error_host = norm_check_general<Tr>(
                'F', 1, batch_count, 1, h_cpu_result, h_hipblas_result_host);
            hipblas_error_device = norm_check_general<Tr>(
                'F', 1, batch_count, 1, h_cpu_result, h_hipblas_result_device);
        }

    } // end of if unit/norm check

    if(argus.timing)
    {
        hipStream_t stream;
        status_1 = hipblasGetStream(handle, &stream);
        status_2 = hipblasSetPointerMode(handle, HIPBLAS_POINTER_MODE_DEVICE);
        if(status_1 != HIPBLAS_STATUS_SUCCESS || status_2 != HIPBLAS_STATUS_SUCCESS)
        {
            hipblasDestroy(handle);
            if(status_1 != HIPBLAS_STATUS_SUCCESS)
                return status_1;
            if(status_2 != HIPBLAS_STATUS_SUCCESS)
                return status_2;
        }

        int runs = argus.cold_iters + argus.iters;
        for(int iter = 0; iter < runs; iter++)
        {
            if(iter == argus.cold_iters)
                gpu_time_used = get_time_us_sync(stream);

            status_1 = hipblasAsumBatched<T, Tr>(
                handle, N, dx_array, incx, batch_count, d_hipblas_result);

            if(status_1 != HIPBLAS_STATUS_SUCCESS)
            {
                hipblasDestroy(handle);
                return status_1;
            }
        }
        gpu_time_used = get_time_us_sync(stream) - gpu_time_used;

        ArgumentModel<e_N, e_incx, e_batch_count>{}.log_args<T>(std::cout,
                                                                argus,
                                                                gpu_time_used,
                                                                asum_gflop_count<T>(N),
                                                                asum_gbyte_count<T>(N),
                                                                hipblas_error_host,
                                                                hipblas_error_device);
    }

    hipblasDestroy(handle);
    return HIPBLAS_STATUS_SUCCESS;
}
