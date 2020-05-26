#ifndef _HIPBLAS_FORTRAN_HPP
#define _HIPBLAS_FORTRAN_HPP

/*!\file
 *  This file interfaces with our Fortran BLAS interface.
 */

/*
 * ============================================================================
 *     Fortran functions
 * ============================================================================
 */
extern "C" {

/* ==========
 *    L1
 * ========== */

// scal
hipblasStatus_t
    hipblasSscalFortran(hipblasHandle_t handle, int n, const float* alpha, float* x, int incx);

hipblasStatus_t
    hipblasDscalFortran(hipblasHandle_t handle, int n, const double* alpha, double* x, int incx);

hipblasStatus_t hipblasCscalFortran(
    hipblasHandle_t handle, int n, const hipblasComplex* alpha, hipblasComplex* x, int incx);

hipblasStatus_t hipblasZscalFortran(hipblasHandle_t             handle,
                                    int                         n,
                                    const hipblasDoubleComplex* alpha,
                                    hipblasDoubleComplex*       x,
                                    int                         incx);

hipblasStatus_t hipblasCsscalFortran(
    hipblasHandle_t handle, int n, const float* alpha, hipblasComplex* x, int incx);

hipblasStatus_t hipblasZdscalFortran(
    hipblasHandle_t handle, int n, const double* alpha, hipblasDoubleComplex* x, int incx);

// scalBatched
hipblasStatus_t hipblasSscalBatchedFortran(
    hipblasHandle_t handle, int n, const float* alpha, float* const x[], int incx, int batch_count);

hipblasStatus_t hipblasDscalBatchedFortran(hipblasHandle_t handle,
                                           int             n,
                                           const double*   alpha,
                                           double* const   x[],
                                           int             incx,
                                           int             batch_count);

hipblasStatus_t hipblasCscalBatchedFortran(hipblasHandle_t       handle,
                                           int                   n,
                                           const hipblasComplex* alpha,
                                           hipblasComplex* const x[],
                                           int                   incx,
                                           int                   batch_count);

hipblasStatus_t hipblasZscalBatchedFortran(hipblasHandle_t             handle,
                                           int                         n,
                                           const hipblasDoubleComplex* alpha,
                                           hipblasDoubleComplex* const x[],
                                           int                         incx,
                                           int                         batch_count);

hipblasStatus_t hipblasCsscalBatchedFortran(hipblasHandle_t       handle,
                                            int                   n,
                                            const float*          alpha,
                                            hipblasComplex* const x[],
                                            int                   incx,
                                            int                   batch_count);

hipblasStatus_t hipblasZdscalBatchedFortran(hipblasHandle_t             handle,
                                            int                         n,
                                            const double*               alpha,
                                            hipblasDoubleComplex* const x[],
                                            int                         incx,
                                            int                         batch_count);

// scalStridedBatched
hipblasStatus_t hipblasSscalStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const float*    alpha,
                                                  float*          x,
                                                  int             incx,
                                                  int             stride_x,
                                                  int             batch_count);

hipblasStatus_t hipblasDscalStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const double*   alpha,
                                                  double*         x,
                                                  int             incx,
                                                  int             stride_x,
                                                  int             batch_count);

hipblasStatus_t hipblasCscalStridedBatchedFortran(hipblasHandle_t       handle,
                                                  int                   n,
                                                  const hipblasComplex* alpha,
                                                  hipblasComplex*       x,
                                                  int                   incx,
                                                  int                   stride_x,
                                                  int                   batch_count);

hipblasStatus_t hipblasZscalStridedBatchedFortran(hipblasHandle_t             handle,
                                                  int                         n,
                                                  const hipblasDoubleComplex* alpha,
                                                  hipblasDoubleComplex*       x,
                                                  int                         incx,
                                                  int                         stride_x,
                                                  int                         batch_count);

hipblasStatus_t hipblasCsscalStridedBatchedFortran(hipblasHandle_t handle,
                                                   int             n,
                                                   const float*    alpha,
                                                   hipblasComplex* x,
                                                   int             incx,
                                                   int             stride_x,
                                                   int             batch_count);

hipblasStatus_t hipblasZdscalStridedBatchedFortran(hipblasHandle_t       handle,
                                                   int                   n,
                                                   const double*         alpha,
                                                   hipblasDoubleComplex* x,
                                                   int                   incx,
                                                   int                   stride_x,
                                                   int                   batch_count);

// copy
hipblasStatus_t hipblasScopyFortran(
    hipblasHandle_t handle, int n, const float* x, int incx, float* y, int incy);

hipblasStatus_t hipblasDcopyFortran(
    hipblasHandle_t handle, int n, const double* x, int incx, double* y, int incy);

hipblasStatus_t hipblasCcopyFortran(
    hipblasHandle_t handle, int n, const hipblasComplex* x, int incx, hipblasComplex* y, int incy);

hipblasStatus_t hipblasZcopyFortran(hipblasHandle_t             handle,
                                    int                         n,
                                    const hipblasDoubleComplex* x,
                                    int                         incx,
                                    hipblasDoubleComplex*       y,
                                    int                         incy);

// copyBatched
hipblasStatus_t hipblasScopyBatchedFortran(hipblasHandle_t    handle,
                                           int                n,
                                           const float* const x[],
                                           int                incx,
                                           float* const       y[],
                                           int                incy,
                                           int                batch_count);

hipblasStatus_t hipblasDcopyBatchedFortran(hipblasHandle_t     handle,
                                           int                 n,
                                           const double* const x[],
                                           int                 incx,
                                           double* const       y[],
                                           int                 incy,
                                           int                 batch_count);

hipblasStatus_t hipblasCcopyBatchedFortran(hipblasHandle_t             handle,
                                           int                         n,
                                           const hipblasComplex* const x[],
                                           int                         incx,
                                           hipblasComplex* const       y[],
                                           int                         incy,
                                           int                         batch_count);

hipblasStatus_t hipblasZcopyBatchedFortran(hipblasHandle_t                   handle,
                                           int                               n,
                                           const hipblasDoubleComplex* const x[],
                                           int                               incx,
                                           hipblasDoubleComplex* const       y[],
                                           int                               incy,
                                           int                               batch_count);

// copyStridedBatched
hipblasStatus_t hipblasScopyStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const float*    x,
                                                  int             incx,
                                                  int             stridex,
                                                  float*          y,
                                                  int             incy,
                                                  int             stridey,
                                                  int             batch_count);

hipblasStatus_t hipblasDcopyStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const double*   x,
                                                  int             incx,
                                                  int             stridex,
                                                  double*         y,
                                                  int             incy,
                                                  int             stridey,
                                                  int             batch_count);

hipblasStatus_t hipblasCcopyStridedBatchedFortran(hipblasHandle_t       handle,
                                                  int                   n,
                                                  const hipblasComplex* x,
                                                  int                   incx,
                                                  int                   stridex,
                                                  hipblasComplex*       y,
                                                  int                   incy,
                                                  int                   stridey,
                                                  int                   batch_count);

hipblasStatus_t hipblasZcopyStridedBatchedFortran(hipblasHandle_t             handle,
                                                  int                         n,
                                                  const hipblasDoubleComplex* x,
                                                  int                         incx,
                                                  int                         stridex,
                                                  hipblasDoubleComplex*       y,
                                                  int                         incy,
                                                  int                         stridey,
                                                  int                         batch_count);

// dot
hipblasStatus_t hipblasSdotFortran(hipblasHandle_t handle,
                                   int             n,
                                   const float*    x,
                                   int             incx,
                                   const float*    y,
                                   int             incy,
                                   float*          result);

hipblasStatus_t hipblasDdotFortran(hipblasHandle_t handle,
                                   int             n,
                                   const double*   x,
                                   int             incx,
                                   const double*   y,
                                   int             incy,
                                   double*         result);

hipblasStatus_t hipblasHdotFortran(hipblasHandle_t    handle,
                                   int                n,
                                   const hipblasHalf* x,
                                   int                incx,
                                   const hipblasHalf* y,
                                   int                incy,
                                   hipblasHalf*       result);

hipblasStatus_t hipblasBfdotFortran(hipblasHandle_t        handle,
                                    int                    n,
                                    const hipblasBfloat16* x,
                                    int                    incx,
                                    const hipblasBfloat16* y,
                                    int                    incy,
                                    hipblasBfloat16*       result);

hipblasStatus_t hipblasCdotuFortran(hipblasHandle_t       handle,
                                    int                   n,
                                    const hipblasComplex* x,
                                    int                   incx,
                                    const hipblasComplex* y,
                                    int                   incy,
                                    hipblasComplex*       result);

hipblasStatus_t hipblasZdotuFortran(hipblasHandle_t             handle,
                                    int                         n,
                                    const hipblasDoubleComplex* x,
                                    int                         incx,
                                    const hipblasDoubleComplex* y,
                                    int                         incy,
                                    hipblasDoubleComplex*       result);

hipblasStatus_t hipblasCdotcFortran(hipblasHandle_t       handle,
                                    int                   n,
                                    const hipblasComplex* x,
                                    int                   incx,
                                    const hipblasComplex* y,
                                    int                   incy,
                                    hipblasComplex*       result);

hipblasStatus_t hipblasZdotcFortran(hipblasHandle_t             handle,
                                    int                         n,
                                    const hipblasDoubleComplex* x,
                                    int                         incx,
                                    const hipblasDoubleComplex* y,
                                    int                         incy,
                                    hipblasDoubleComplex*       result);

// dotBatched
hipblasStatus_t hipblasSdotBatchedFortran(hipblasHandle_t    handle,
                                          int                n,
                                          const float* const x[],
                                          int                incx,
                                          const float* const y[],
                                          int                incy,
                                          int                batch_count,
                                          float*             result);

hipblasStatus_t hipblasDdotBatchedFortran(hipblasHandle_t     handle,
                                          int                 n,
                                          const double* const x[],
                                          int                 incx,
                                          const double* const y[],
                                          int                 incy,
                                          int                 batch_count,
                                          double*             result);

hipblasStatus_t hipblasHdotBatchedFortran(hipblasHandle_t          handle,
                                          int                      n,
                                          const hipblasHalf* const x[],
                                          int                      incx,
                                          const hipblasHalf* const y[],
                                          int                      incy,
                                          int                      batch_count,
                                          hipblasHalf*             result);

hipblasStatus_t hipblasBfdotBatchedFortran(hipblasHandle_t              handle,
                                           int                          n,
                                           const hipblasBfloat16* const x[],
                                           int                          incx,
                                           const hipblasBfloat16* const y[],
                                           int                          incy,
                                           int                          batch_count,
                                           hipblasBfloat16*             result);

hipblasStatus_t hipblasCdotuBatchedFortran(hipblasHandle_t             handle,
                                           int                         n,
                                           const hipblasComplex* const x[],
                                           int                         incx,
                                           const hipblasComplex* const y[],
                                           int                         incy,
                                           int                         batch_count,
                                           hipblasComplex*             result);

hipblasStatus_t hipblasZdotuBatchedFortran(hipblasHandle_t                   handle,
                                           int                               n,
                                           const hipblasDoubleComplex* const x[],
                                           int                               incx,
                                           const hipblasDoubleComplex* const y[],
                                           int                               incy,
                                           int                               batch_count,
                                           hipblasDoubleComplex*             result);

hipblasStatus_t hipblasCdotcBatchedFortran(hipblasHandle_t             handle,
                                           int                         n,
                                           const hipblasComplex* const x[],
                                           int                         incx,
                                           const hipblasComplex* const y[],
                                           int                         incy,
                                           int                         batch_count,
                                           hipblasComplex*             result);

hipblasStatus_t hipblasZdotcBatchedFortran(hipblasHandle_t                   handle,
                                           int                               n,
                                           const hipblasDoubleComplex* const x[],
                                           int                               incx,
                                           const hipblasDoubleComplex* const y[],
                                           int                               incy,
                                           int                               batch_count,
                                           hipblasDoubleComplex*             result);

// dotStridedBatched
hipblasStatus_t hipblasSdotStridedBatchedFortran(hipblasHandle_t handle,
                                                 int             n,
                                                 const float*    x,
                                                 int             incx,
                                                 int             stridex,
                                                 const float*    y,
                                                 int             incy,
                                                 int             stridey,
                                                 int             batch_count,
                                                 float*          result);

hipblasStatus_t hipblasDdotStridedBatchedFortran(hipblasHandle_t handle,
                                                 int             n,
                                                 const double*   x,
                                                 int             incx,
                                                 int             stridex,
                                                 const double*   y,
                                                 int             incy,
                                                 int             stridey,
                                                 int             batch_count,
                                                 double*         result);

hipblasStatus_t hipblasHdotStridedBatchedFortran(hipblasHandle_t    handle,
                                                 int                n,
                                                 const hipblasHalf* x,
                                                 int                incx,
                                                 int                stridex,
                                                 const hipblasHalf* y,
                                                 int                incy,
                                                 int                stridey,
                                                 int                batch_count,
                                                 hipblasHalf*       result);

hipblasStatus_t hipblasBfdotStridedBatchedFortran(hipblasHandle_t        handle,
                                                  int                    n,
                                                  const hipblasBfloat16* x,
                                                  int                    incx,
                                                  int                    stridex,
                                                  const hipblasBfloat16* y,
                                                  int                    incy,
                                                  int                    stridey,
                                                  int                    batch_count,
                                                  hipblasBfloat16*       result);

hipblasStatus_t hipblasCdotuStridedBatchedFortran(hipblasHandle_t       handle,
                                                  int                   n,
                                                  const hipblasComplex* x,
                                                  int                   incx,
                                                  int                   stridex,
                                                  const hipblasComplex* y,
                                                  int                   incy,
                                                  int                   stridey,
                                                  int                   batch_count,
                                                  hipblasComplex*       result);

hipblasStatus_t hipblasZdotuStridedBatchedFortran(hipblasHandle_t             handle,
                                                  int                         n,
                                                  const hipblasDoubleComplex* x,
                                                  int                         incx,
                                                  int                         stridex,
                                                  const hipblasDoubleComplex* y,
                                                  int                         incy,
                                                  int                         stridey,
                                                  int                         batch_count,
                                                  hipblasDoubleComplex*       result);

hipblasStatus_t hipblasCdotcStridedBatchedFortran(hipblasHandle_t       handle,
                                                  int                   n,
                                                  const hipblasComplex* x,
                                                  int                   incx,
                                                  int                   stridex,
                                                  const hipblasComplex* y,
                                                  int                   incy,
                                                  int                   stridey,
                                                  int                   batch_count,
                                                  hipblasComplex*       result);

hipblasStatus_t hipblasZdotcStridedBatchedFortran(hipblasHandle_t             handle,
                                                  int                         n,
                                                  const hipblasDoubleComplex* x,
                                                  int                         incx,
                                                  int                         stridex,
                                                  const hipblasDoubleComplex* y,
                                                  int                         incy,
                                                  int                         stridey,
                                                  int                         batch_count,
                                                  hipblasDoubleComplex*       result);

// swap
hipblasStatus_t
    hipblasSswapFortran(hipblasHandle_t handle, int n, float* x, int incx, float* y, int incy);

hipblasStatus_t
    hipblasDswapFortran(hipblasHandle_t handle, int n, double* x, int incx, double* y, int incy);

hipblasStatus_t hipblasCswapFortran(
    hipblasHandle_t handle, int n, hipblasComplex* x, int incx, hipblasComplex* y, int incy);

hipblasStatus_t hipblasZswapFortran(hipblasHandle_t       handle,
                                    int                   n,
                                    hipblasDoubleComplex* x,
                                    int                   incx,
                                    hipblasDoubleComplex* y,
                                    int                   incy);

// swapBatched
hipblasStatus_t hipblasSswapBatchedFortran(
    hipblasHandle_t handle, int n, float* x[], int incx, float* y[], int incy, int batch_count);

hipblasStatus_t hipblasDswapBatchedFortran(
    hipblasHandle_t handle, int n, double* x[], int incx, double* y[], int incy, int batch_count);

hipblasStatus_t hipblasCswapBatchedFortran(hipblasHandle_t handle,
                                           int             n,
                                           hipblasComplex* x[],
                                           int             incx,
                                           hipblasComplex* y[],
                                           int             incy,
                                           int             batch_count);

hipblasStatus_t hipblasZswapBatchedFortran(hipblasHandle_t       handle,
                                           int                   n,
                                           hipblasDoubleComplex* x[],
                                           int                   incx,
                                           hipblasDoubleComplex* y[],
                                           int                   incy,
                                           int                   batch_count);

// swapStridedBatched
hipblasStatus_t hipblasSswapStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  float*          x,
                                                  int             incx,
                                                  int             stridex,
                                                  float*          y,
                                                  int             incy,
                                                  int             stridey,
                                                  int             batch_count);

hipblasStatus_t hipblasDswapStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  double*         x,
                                                  int             incx,
                                                  int             stridex,
                                                  double*         y,
                                                  int             incy,
                                                  int             stridey,
                                                  int             batch_count);

hipblasStatus_t hipblasCswapStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  hipblasComplex* x,
                                                  int             incx,
                                                  int             stridex,
                                                  hipblasComplex* y,
                                                  int             incy,
                                                  int             stridey,
                                                  int             batch_count);

hipblasStatus_t hipblasZswapStridedBatchedFortran(hipblasHandle_t       handle,
                                                  int                   n,
                                                  hipblasDoubleComplex* x,
                                                  int                   incx,
                                                  int                   stridex,
                                                  hipblasDoubleComplex* y,
                                                  int                   incy,
                                                  int                   stridey,
                                                  int                   batch_count);

// axpy
hipblasStatus_t hipblasHaxpyFortran(hipblasHandle_t    handle,
                                    const int          N,
                                    const hipblasHalf* alpha,
                                    const hipblasHalf* x,
                                    const int          incx,
                                    hipblasHalf*       y,
                                    const int          incy);

hipblasStatus_t hipblasSaxpyFortran(hipblasHandle_t handle,
                                    const int       N,
                                    const float*    alpha,
                                    const float*    x,
                                    const int       incx,
                                    float*          y,
                                    const int       incy);

hipblasStatus_t hipblasDaxpyFortran(hipblasHandle_t handle,
                                    const int       N,
                                    const double*   alpha,
                                    const double*   x,
                                    const int       incx,
                                    double*         y,
                                    const int       incy);

hipblasStatus_t hipblasCaxpyFortran(hipblasHandle_t       handle,
                                    const int             N,
                                    const hipblasComplex* alpha,
                                    const hipblasComplex* x,
                                    const int             incx,
                                    hipblasComplex*       y,
                                    const int             incy);

hipblasStatus_t hipblasZaxpyFortran(hipblasHandle_t             handle,
                                    const int                   N,
                                    const hipblasDoubleComplex* alpha,
                                    const hipblasDoubleComplex* x,
                                    const int                   incx,
                                    hipblasDoubleComplex*       y,
                                    const int                   incy);

// axpyBatched
hipblasStatus_t hipblasHaxpyBatchedFortran(hipblasHandle_t          handle,
                                           const int                N,
                                           const hipblasHalf*       alpha,
                                           const hipblasHalf* const x[],
                                           const int                incx,
                                           hipblasHalf* const       y[],
                                           const int                incy,
                                           const int                batch_count);

hipblasStatus_t hipblasSaxpyBatchedFortran(hipblasHandle_t    handle,
                                           const int          N,
                                           const float*       alpha,
                                           const float* const x[],
                                           const int          incx,
                                           float* const       y[],
                                           const int          incy,
                                           const int          batch_count);

hipblasStatus_t hipblasSaxpyBatchedFortran(hipblasHandle_t    handle,
                                           const int          N,
                                           const float*       alpha,
                                           const float* const x[],
                                           const int          incx,
                                           float* const       y[],
                                           const int          incy,
                                           const int          batch_count);

hipblasStatus_t hipblasDaxpyBatchedFortran(hipblasHandle_t     handle,
                                           const int           N,
                                           const double*       alpha,
                                           const double* const x[],
                                           const int           incx,
                                           double* const       y[],
                                           const int           incy,
                                           const int           batch_count);

hipblasStatus_t hipblasCaxpyBatchedFortran(hipblasHandle_t             handle,
                                           const int                   N,
                                           const hipblasComplex*       alpha,
                                           const hipblasComplex* const x[],
                                           const int                   incx,
                                           hipblasComplex* const       y[],
                                           const int                   incy,
                                           const int                   batch_count);

hipblasStatus_t hipblasZaxpyBatchedFortran(hipblasHandle_t                   handle,
                                           const int                         N,
                                           const hipblasDoubleComplex*       alpha,
                                           const hipblasDoubleComplex* const x[],
                                           const int                         incx,
                                           hipblasDoubleComplex* const       y[],
                                           const int                         incy,
                                           const int                         batch_count);

// axpyStridedBatched
hipblasStatus_t hipblasHaxpyStridedBatchedFortran(hipblasHandle_t    handle,
                                                  const int          N,
                                                  const hipblasHalf* alpha,
                                                  const hipblasHalf* x,
                                                  const int          incx,
                                                  const int          stride_x,
                                                  hipblasHalf*       y,
                                                  const int          incy,
                                                  const int          stride_y,
                                                  const int          batch_count);

hipblasStatus_t hipblasSaxpyStridedBatchedFortran(hipblasHandle_t handle,
                                                  const int       N,
                                                  const float*    alpha,
                                                  const float*    x,
                                                  const int       incx,
                                                  const int       stride_x,
                                                  float*          y,
                                                  const int       incy,
                                                  const int       stride_y,
                                                  const int       batch_count);

hipblasStatus_t hipblasDaxpyStridedBatchedFortran(hipblasHandle_t handle,
                                                  const int       N,
                                                  const double*   alpha,
                                                  const double*   x,
                                                  const int       incx,
                                                  const int       stride_x,
                                                  double*         y,
                                                  const int       incy,
                                                  const int       stride_y,
                                                  const int       batch_count);

hipblasStatus_t hipblasCaxpyStridedBatchedFortran(hipblasHandle_t       handle,
                                                  const int             N,
                                                  const hipblasComplex* alpha,
                                                  const hipblasComplex* x,
                                                  const int             incx,
                                                  const int             stride_x,
                                                  hipblasComplex*       y,
                                                  const int             incy,
                                                  const int             stride_y,
                                                  const int             batch_count);

hipblasStatus_t hipblasZaxpyStridedBatchedFortran(hipblasHandle_t             handle,
                                                  const int                   N,
                                                  const hipblasDoubleComplex* alpha,
                                                  const hipblasDoubleComplex* x,
                                                  const int                   incx,
                                                  const int                   stride_x,
                                                  hipblasDoubleComplex*       y,
                                                  const int                   incy,
                                                  const int                   stride_y,
                                                  const int                   batch_count);

// asum
hipblasStatus_t
    hipblasSasumFortran(hipblasHandle_t handle, int n, const float* x, int incx, float* result);

hipblasStatus_t
    hipblasDasumFortran(hipblasHandle_t handle, int n, const double* x, int incx, double* result);

hipblasStatus_t hipblasScasumFortran(
    hipblasHandle_t handle, int n, const hipblasComplex* x, int incx, float* result);

hipblasStatus_t hipblasDzasumFortran(
    hipblasHandle_t handle, int n, const hipblasDoubleComplex* x, int incx, double* result);

// asumBatched
hipblasStatus_t hipblasSasumBatchedFortran(hipblasHandle_t    handle,
                                           int                n,
                                           const float* const x[],
                                           int                incx,
                                           int                batch_count,
                                           float*             results);

hipblasStatus_t hipblasDasumBatchedFortran(hipblasHandle_t     handle,
                                           int                 n,
                                           const double* const x[],
                                           int                 incx,
                                           int                 batch_count,
                                           double*             results);

hipblasStatus_t hipblasScasumBatchedFortran(hipblasHandle_t             handle,
                                            int                         n,
                                            const hipblasComplex* const x[],
                                            int                         incx,
                                            int                         batch_count,
                                            float*                      results);

hipblasStatus_t hipblasDzasumBatchedFortran(hipblasHandle_t                   handle,
                                            int                               n,
                                            const hipblasDoubleComplex* const x[],
                                            int                               incx,
                                            int                               batch_count,
                                            double*                           results);

// asumStridedBatched
hipblasStatus_t hipblasSasumStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const float*    x,
                                                  int             incx,
                                                  int             stridex,
                                                  int             batch_count,
                                                  float*          results);

hipblasStatus_t hipblasDasumStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const double*   x,
                                                  int             incx,
                                                  int             stridex,
                                                  int             batch_count,
                                                  double*         results);

hipblasStatus_t hipblasScasumStridedBatchedFortran(hipblasHandle_t       handle,
                                                   int                   n,
                                                   const hipblasComplex* x,
                                                   int                   incx,
                                                   int                   stridex,
                                                   int                   batch_count,
                                                   float*                results);

hipblasStatus_t hipblasDzasumStridedBatchedFortran(hipblasHandle_t             handle,
                                                   int                         n,
                                                   const hipblasDoubleComplex* x,
                                                   int                         incx,
                                                   int                         stridex,
                                                   int                         batch_count,
                                                   double*                     results);

// nrm2
hipblasStatus_t
    hipblasSnrm2Fortran(hipblasHandle_t handle, int n, const float* x, int incx, float* result);

hipblasStatus_t
    hipblasDnrm2Fortran(hipblasHandle_t handle, int n, const double* x, int incx, double* result);

hipblasStatus_t hipblasScnrm2Fortran(
    hipblasHandle_t handle, int n, const hipblasComplex* x, int incx, float* result);

hipblasStatus_t hipblasDznrm2Fortran(
    hipblasHandle_t handle, int n, const hipblasDoubleComplex* x, int incx, double* result);

// nrm2Batched
hipblasStatus_t hipblasSnrm2BatchedFortran(hipblasHandle_t    handle,
                                           int                n,
                                           const float* const x[],
                                           int                incx,
                                           int                batch_count,
                                           float*             results);

hipblasStatus_t hipblasDnrm2BatchedFortran(hipblasHandle_t     handle,
                                           int                 n,
                                           const double* const x[],
                                           int                 incx,
                                           int                 batch_count,
                                           double*             results);

hipblasStatus_t hipblasScnrm2BatchedFortran(hipblasHandle_t             handle,
                                            int                         n,
                                            const hipblasComplex* const x[],
                                            int                         incx,
                                            int                         batch_count,
                                            float*                      results);

hipblasStatus_t hipblasDznrm2BatchedFortran(hipblasHandle_t                   handle,
                                            int                               n,
                                            const hipblasDoubleComplex* const x[],
                                            int                               incx,
                                            int                               batch_count,
                                            double*                           results);

// nrm2StridedBatched
hipblasStatus_t hipblasSnrm2StridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const float*    x,
                                                  int             incx,
                                                  int             stridex,
                                                  int             batch_count,
                                                  float*          results);

hipblasStatus_t hipblasDnrm2StridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  const double*   x,
                                                  int             incx,
                                                  int             stridex,
                                                  int             batch_count,
                                                  double*         results);

hipblasStatus_t hipblasScnrm2StridedBatchedFortran(hipblasHandle_t       handle,
                                                   int                   n,
                                                   const hipblasComplex* x,
                                                   int                   incx,
                                                   int                   stridex,
                                                   int                   batch_count,
                                                   float*                results);

hipblasStatus_t hipblasDznrm2StridedBatchedFortran(hipblasHandle_t             handle,
                                                   int                         n,
                                                   const hipblasDoubleComplex* x,
                                                   int                         incx,
                                                   int                         stridex,
                                                   int                         batch_count,
                                                   double*                     results);

// amax
hipblasStatus_t
    hipblasIsamaxFortran(hipblasHandle_t handle, int n, const float* x, int incx, int* result);

hipblasStatus_t
    hipblasIdamaxFortran(hipblasHandle_t handle, int n, const double* x, int incx, int* result);

hipblasStatus_t hipblasIcamaxFortran(
    hipblasHandle_t handle, int n, const hipblasComplex* x, int incx, int* result);

hipblasStatus_t hipblasIzamaxFortran(
    hipblasHandle_t handle, int n, const hipblasDoubleComplex* x, int incx, int* result);

// amaxBatched
hipblasStatus_t hipblasIsamaxBatchedFortran(
    hipblasHandle_t handle, int n, const float* const x[], int incx, int batch_count, int* result);

hipblasStatus_t hipblasIdamaxBatchedFortran(
    hipblasHandle_t handle, int n, const double* const x[], int incx, int batch_count, int* result);

hipblasStatus_t hipblasIcamaxBatchedFortran(hipblasHandle_t             handle,
                                            int                         n,
                                            const hipblasComplex* const x[],
                                            int                         incx,
                                            int                         batch_count,
                                            int*                        result);

hipblasStatus_t hipblasIzamaxBatchedFortran(hipblasHandle_t                   handle,
                                            int                               n,
                                            const hipblasDoubleComplex* const x[],
                                            int                               incx,
                                            int                               batch_count,
                                            int*                              result);

// amaxStridedBatched
hipblasStatus_t hipblasIsamaxStridedBatchedFortran(hipblasHandle_t handle,
                                                   int             n,
                                                   const float*    x,
                                                   int             incx,
                                                   int             stridex,
                                                   int             batch_count,
                                                   int*            result);

hipblasStatus_t hipblasIdamaxStridedBatchedFortran(hipblasHandle_t handle,
                                                   int             n,
                                                   const double*   x,
                                                   int             incx,
                                                   int             stridex,
                                                   int             batch_count,
                                                   int*            result);

hipblasStatus_t hipblasIcamaxStridedBatchedFortran(hipblasHandle_t       handle,
                                                   int                   n,
                                                   const hipblasComplex* x,
                                                   int                   incx,
                                                   int                   stridex,
                                                   int                   batch_count,
                                                   int*                  result);

hipblasStatus_t hipblasIzamaxStridedBatchedFortran(hipblasHandle_t             handle,
                                                   int                         n,
                                                   const hipblasDoubleComplex* x,
                                                   int                         incx,
                                                   int                         stridex,
                                                   int                         batch_count,
                                                   int*                        result);

// amin
hipblasStatus_t
    hipblasIsaminFortran(hipblasHandle_t handle, int n, const float* x, int incx, int* result);

hipblasStatus_t
    hipblasIdaminFortran(hipblasHandle_t handle, int n, const double* x, int incx, int* result);

hipblasStatus_t hipblasIcaminFortran(
    hipblasHandle_t handle, int n, const hipblasComplex* x, int incx, int* result);

hipblasStatus_t hipblasIzaminFortran(
    hipblasHandle_t handle, int n, const hipblasDoubleComplex* x, int incx, int* result);

// aminBatched
hipblasStatus_t hipblasIsaminBatchedFortran(
    hipblasHandle_t handle, int n, const float* const x[], int incx, int batch_count, int* result);

hipblasStatus_t hipblasIdaminBatchedFortran(
    hipblasHandle_t handle, int n, const double* const x[], int incx, int batch_count, int* result);

hipblasStatus_t hipblasIcaminBatchedFortran(hipblasHandle_t             handle,
                                            int                         n,
                                            const hipblasComplex* const x[],
                                            int                         incx,
                                            int                         batch_count,
                                            int*                        result);

hipblasStatus_t hipblasIzaminBatchedFortran(hipblasHandle_t                   handle,
                                            int                               n,
                                            const hipblasDoubleComplex* const x[],
                                            int                               incx,
                                            int                               batch_count,
                                            int*                              result);

// aminStridedBatched
hipblasStatus_t hipblasIsaminStridedBatchedFortran(hipblasHandle_t handle,
                                                   int             n,
                                                   const float*    x,
                                                   int             incx,
                                                   int             stridex,
                                                   int             batch_count,
                                                   int*            result);

hipblasStatus_t hipblasIdaminStridedBatchedFortran(hipblasHandle_t handle,
                                                   int             n,
                                                   const double*   x,
                                                   int             incx,
                                                   int             stridex,
                                                   int             batch_count,
                                                   int*            result);

hipblasStatus_t hipblasIcaminStridedBatchedFortran(hipblasHandle_t       handle,
                                                   int                   n,
                                                   const hipblasComplex* x,
                                                   int                   incx,
                                                   int                   stridex,
                                                   int                   batch_count,
                                                   int*                  result);

hipblasStatus_t hipblasIzaminStridedBatchedFortran(hipblasHandle_t             handle,
                                                   int                         n,
                                                   const hipblasDoubleComplex* x,
                                                   int                         incx,
                                                   int                         stridex,
                                                   int                         batch_count,
                                                   int*                        result);

// rot
hipblasStatus_t hipblasSrotFortran(hipblasHandle_t handle,
                                   int             n,
                                   float*          x,
                                   int             incx,
                                   float*          y,
                                   int             incy,
                                   const float*    c,
                                   const float*    s);

hipblasStatus_t hipblasDrotFortran(hipblasHandle_t handle,
                                   int             n,
                                   double*         x,
                                   int             incx,
                                   double*         y,
                                   int             incy,
                                   const double*   c,
                                   const double*   s);

hipblasStatus_t hipblasCrotFortran(hipblasHandle_t       handle,
                                   int                   n,
                                   hipblasComplex*       x,
                                   int                   incx,
                                   hipblasComplex*       y,
                                   int                   incy,
                                   const float*          c,
                                   const hipblasComplex* s);

hipblasStatus_t hipblasCsrotFortran(hipblasHandle_t handle,
                                    int             n,
                                    hipblasComplex* x,
                                    int             incx,
                                    hipblasComplex* y,
                                    int             incy,
                                    const float*    c,
                                    const float*    s);

hipblasStatus_t hipblasZrotFortran(hipblasHandle_t             handle,
                                   int                         n,
                                   hipblasDoubleComplex*       x,
                                   int                         incx,
                                   hipblasDoubleComplex*       y,
                                   int                         incy,
                                   const double*               c,
                                   const hipblasDoubleComplex* s);

hipblasStatus_t hipblasZdrotFortran(hipblasHandle_t       handle,
                                    int                   n,
                                    hipblasDoubleComplex* x,
                                    int                   incx,
                                    hipblasDoubleComplex* y,
                                    int                   incy,
                                    const double*         c,
                                    const double*         s);

// rotBatched
hipblasStatus_t hipblasSrotBatchedFortran(hipblasHandle_t handle,
                                          int             n,
                                          float* const    x[],
                                          int             incx,
                                          float* const    y[],
                                          int             incy,
                                          const float*    c,
                                          const float*    s,
                                          int             batch_count);

hipblasStatus_t hipblasDrotBatchedFortran(hipblasHandle_t handle,
                                          int             n,
                                          double* const   x[],
                                          int             incx,
                                          double* const   y[],
                                          int             incy,
                                          const double*   c,
                                          const double*   s,
                                          int             batch_count);

hipblasStatus_t hipblasCrotBatchedFortran(hipblasHandle_t       handle,
                                          int                   n,
                                          hipblasComplex* const x[],
                                          int                   incx,
                                          hipblasComplex* const y[],
                                          int                   incy,
                                          const float*          c,
                                          const hipblasComplex* s,
                                          int                   batch_count);

hipblasStatus_t hipblasCsrotBatchedFortran(hipblasHandle_t       handle,
                                           int                   n,
                                           hipblasComplex* const x[],
                                           int                   incx,
                                           hipblasComplex* const y[],
                                           int                   incy,
                                           const float*          c,
                                           const float*          s,
                                           int                   batch_count);

hipblasStatus_t hipblasZrotBatchedFortran(hipblasHandle_t             handle,
                                          int                         n,
                                          hipblasDoubleComplex* const x[],
                                          int                         incx,
                                          hipblasDoubleComplex* const y[],
                                          int                         incy,
                                          const double*               c,
                                          const hipblasDoubleComplex* s,
                                          int                         batch_count);

hipblasStatus_t hipblasZdrotBatchedFortran(hipblasHandle_t             handle,
                                           int                         n,
                                           hipblasDoubleComplex* const x[],
                                           int                         incx,
                                           hipblasDoubleComplex* const y[],
                                           int                         incy,
                                           const double*               c,
                                           const double*               s,
                                           int                         batch_count);

// rotStridedBatched
hipblasStatus_t hipblasSrotStridedBatchedFortran(hipblasHandle_t handle,
                                                 int             n,
                                                 float*          x,
                                                 int             incx,
                                                 int             stride_x,
                                                 float*          y,
                                                 int             incy,
                                                 int             stride_y,
                                                 const float*    c,
                                                 const float*    s,
                                                 int             batch_count);

hipblasStatus_t hipblasDrotStridedBatchedFortran(hipblasHandle_t handle,
                                                 int             n,
                                                 double*         x,
                                                 int             incx,
                                                 int             stride_x,
                                                 double*         y,
                                                 int             incy,
                                                 int             stride_y,
                                                 const double*   c,
                                                 const double*   s,
                                                 int             batch_count);

hipblasStatus_t hipblasCrotStridedBatchedFortran(hipblasHandle_t       handle,
                                                 int                   n,
                                                 hipblasComplex*       x,
                                                 int                   incx,
                                                 int                   stride_x,
                                                 hipblasComplex*       y,
                                                 int                   incy,
                                                 int                   stride_y,
                                                 const float*          c,
                                                 const hipblasComplex* s,
                                                 int                   batch_count);

hipblasStatus_t hipblasCsrotStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  hipblasComplex* x,
                                                  int             incx,
                                                  int             stride_x,
                                                  hipblasComplex* y,
                                                  int             incy,
                                                  int             stride_y,
                                                  const float*    c,
                                                  const float*    s,
                                                  int             batch_count);

hipblasStatus_t hipblasZrotStridedBatchedFortran(hipblasHandle_t             handle,
                                                 int                         n,
                                                 hipblasDoubleComplex*       x,
                                                 int                         incx,
                                                 int                         stride_x,
                                                 hipblasDoubleComplex*       y,
                                                 int                         incy,
                                                 int                         stride_y,
                                                 const double*               c,
                                                 const hipblasDoubleComplex* s,
                                                 int                         batch_count);

hipblasStatus_t hipblasZdrotStridedBatchedFortran(hipblasHandle_t       handle,
                                                  int                   n,
                                                  hipblasDoubleComplex* x,
                                                  int                   incx,
                                                  int                   stride_x,
                                                  hipblasDoubleComplex* y,
                                                  int                   incy,
                                                  int                   stride_y,
                                                  const double*         c,
                                                  const double*         s,
                                                  int                   batch_count);

// rotg
hipblasStatus_t hipblasSrotgFortran(hipblasHandle_t handle, float* a, float* b, float* c, float* s);

hipblasStatus_t
    hipblasDrotgFortran(hipblasHandle_t handle, double* a, double* b, double* c, double* s);

hipblasStatus_t hipblasCrotgFortran(
    hipblasHandle_t handle, hipblasComplex* a, hipblasComplex* b, float* c, hipblasComplex* s);

hipblasStatus_t hipblasZrotgFortran(hipblasHandle_t       handle,
                                    hipblasDoubleComplex* a,
                                    hipblasDoubleComplex* b,
                                    double*               c,
                                    hipblasDoubleComplex* s);

// rotgBatched
hipblasStatus_t hipblasSrotgBatchedFortran(hipblasHandle_t handle,
                                           float* const    a[],
                                           float* const    b[],
                                           float* const    c[],
                                           float* const    s[],
                                           int             batch_count);

hipblasStatus_t hipblasDrotgBatchedFortran(hipblasHandle_t handle,
                                           double* const   a[],
                                           double* const   b[],
                                           double* const   c[],
                                           double* const   s[],
                                           int             batch_count);

hipblasStatus_t hipblasCrotgBatchedFortran(hipblasHandle_t       handle,
                                           hipblasComplex* const a[],
                                           hipblasComplex* const b[],
                                           float* const          c[],
                                           hipblasComplex* const s[],
                                           int                   batch_count);

hipblasStatus_t hipblasZrotgBatchedFortran(hipblasHandle_t             handle,
                                           hipblasDoubleComplex* const a[],
                                           hipblasDoubleComplex* const b[],
                                           double* const               c[],
                                           hipblasDoubleComplex* const s[],
                                           int                         batch_count);

// rotgStridedBatched
hipblasStatus_t hipblasSrotgStridedBatchedFortran(hipblasHandle_t handle,
                                                  float*          a,
                                                  int             stride_a,
                                                  float*          b,
                                                  int             stride_b,
                                                  float*          c,
                                                  int             stride_c,
                                                  float*          s,
                                                  int             stride_s,
                                                  int             batch_count);

hipblasStatus_t hipblasDrotgStridedBatchedFortran(hipblasHandle_t handle,
                                                  double*         a,
                                                  int             stride_a,
                                                  double*         b,
                                                  int             stride_b,
                                                  double*         c,
                                                  int             stride_c,
                                                  double*         s,
                                                  int             stride_s,
                                                  int             batch_count);

hipblasStatus_t hipblasCrotgStridedBatchedFortran(hipblasHandle_t handle,
                                                  hipblasComplex* a,
                                                  int             stride_a,
                                                  hipblasComplex* b,
                                                  int             stride_b,
                                                  float*          c,
                                                  int             stride_c,
                                                  hipblasComplex* s,
                                                  int             stride_s,
                                                  int             batch_count);

hipblasStatus_t hipblasZrotgStridedBatchedFortran(hipblasHandle_t       handle,
                                                  hipblasDoubleComplex* a,
                                                  int                   stride_a,
                                                  hipblasDoubleComplex* b,
                                                  int                   stride_b,
                                                  double*               c,
                                                  int                   stride_c,
                                                  hipblasDoubleComplex* s,
                                                  int                   stride_s,
                                                  int                   batch_count);

// rotm
hipblasStatus_t hipblasSrotmFortran(
    hipblasHandle_t handle, int n, float* x, int incx, float* y, int incy, const float* param);

hipblasStatus_t hipblasDrotmFortran(
    hipblasHandle_t handle, int n, double* x, int incx, double* y, int incy, const double* param);

// rotmBatched
hipblasStatus_t hipblasSrotmBatchedFortran(hipblasHandle_t    handle,
                                           int                n,
                                           float* const       x[],
                                           int                incx,
                                           float* const       y[],
                                           int                incy,
                                           const float* const param[],
                                           int                batch_count);

hipblasStatus_t hipblasDrotmBatchedFortran(hipblasHandle_t     handle,
                                           int                 n,
                                           double* const       x[],
                                           int                 incx,
                                           double* const       y[],
                                           int                 incy,
                                           const double* const param[],
                                           int                 batch_count);

// rotmStridedBatched
hipblasStatus_t hipblasSrotmStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  float*          x,
                                                  int             incx,
                                                  int             stride_x,
                                                  float*          y,
                                                  int             incy,
                                                  int             stride_y,
                                                  const float*    param,
                                                  int             stride_param,
                                                  int             batch_count);

hipblasStatus_t hipblasDrotmStridedBatchedFortran(hipblasHandle_t handle,
                                                  int             n,
                                                  double*         x,
                                                  int             incx,
                                                  int             stride_x,
                                                  double*         y,
                                                  int             incy,
                                                  int             stride_y,
                                                  const double*   param,
                                                  int             stride_param,
                                                  int             batch_count);

// rotmg
hipblasStatus_t hipblasSrotmgFortran(
    hipblasHandle_t handle, float* d1, float* d2, float* x1, const float* y1, float* param);

hipblasStatus_t hipblasDrotmgFortran(
    hipblasHandle_t handle, double* d1, double* d2, double* x1, const double* y1, double* param);

// rotmgBatched
hipblasStatus_t hipblasSrotmgBatchedFortran(hipblasHandle_t    handle,
                                            float* const       d1[],
                                            float* const       d2[],
                                            float* const       x1[],
                                            const float* const y1[],
                                            float* const       param[],
                                            int                batch_count);

hipblasStatus_t hipblasDrotmgBatchedFortran(hipblasHandle_t     handle,
                                            double* const       d1[],
                                            double* const       d2[],
                                            double* const       x1[],
                                            const double* const y1[],
                                            double* const       param[],
                                            int                 batch_count);

// rotmgStridedBatched
hipblasStatus_t hipblasSrotmgStridedBatchedFortran(hipblasHandle_t handle,
                                                   float*          d1,
                                                   int             stride_d1,
                                                   float*          d2,
                                                   int             stride_d2,
                                                   float*          x1,
                                                   int             stride_x1,
                                                   const float*    y1,
                                                   int             stride_y1,
                                                   float*          param,
                                                   int             stride_param,
                                                   int             batch_count);

hipblasStatus_t hipblasDrotmgStridedBatchedFortran(hipblasHandle_t handle,
                                                   double*         d1,
                                                   int             stride_d1,
                                                   double*         d2,
                                                   int             stride_d2,
                                                   double*         x1,
                                                   int             stride_x1,
                                                   const double*   y1,
                                                   int             stride_y1,
                                                   double*         param,
                                                   int             stride_param,
                                                   int             batch_count);
}

#endif
