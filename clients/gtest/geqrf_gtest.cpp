/* ************************************************************************
 * Copyright 2016-2020 Advanced Micro Devices, Inc.
 *
 * ************************************************************************ */

#include "testing_geqrf.hpp"
#include "utility.h"
#include <gtest/gtest.h>
#include <math.h>
#include <stdexcept>
#include <vector>

using ::testing::Combine;
using ::testing::TestWithParam;
using ::testing::Values;
using ::testing::ValuesIn;
using namespace std;

typedef std::tuple<vector<int>, double, int> geqrf_tuple;

const vector<vector<int>> matrix_size_range = {{-1, -1, 1, 1},
                                               {10, 10, 10, 10},
                                               {10, 10, 20, 100},
                                               {600, 500, 600, 600},
                                               {1024, 1024, 1024, 1024}};

const vector<double> stride_scale_range = {2.5};

const vector<int> batch_count_range = {1};

Arguments setup_geqrf_arguments(geqrf_tuple tup)
{
    vector<int> matrix_size  = std::get<0>(tup);
    double      stride_scale = std::get<1>(tup);
    int         batch_count  = std::get<2>(tup);

    Arguments arg;

    arg.M   = matrix_size[0];
    arg.N   = matrix_size[1];
    arg.lda = matrix_size[2];
    //arg.ldb = matrix_size[3];

    arg.stride_scale = stride_scale;
    arg.batch_count  = batch_count;

    return arg;
}

class geqrf_gtest : public ::TestWithParam<geqrf_tuple>
{
protected:
    geqrf_gtest() {}
    virtual ~geqrf_gtest() {}
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_P(geqrf_gtest, geqrf_gtest_float)
{
    // GetParam returns a tuple. The setup routine unpacks the tuple
    // and initializes arg(Arguments), which will be passed to testing routine.

    Arguments arg = setup_geqrf_arguments(GetParam());

    hipblasStatus_t status = testing_geqrf<float>(arg);

    if(status != HIPBLAS_STATUS_SUCCESS)
    {
        if(arg.M < 0 || arg.N < 0 || arg.lda < arg.M)
        {
            EXPECT_EQ(HIPBLAS_STATUS_INVALID_VALUE, status);
        }
        else
        {
            EXPECT_EQ(HIPBLAS_STATUS_SUCCESS, status);
        }
    }
}

TEST_P(geqrf_gtest, geqrf_gtest_double)
{
    // GetParam returns a tuple. The setup routine unpacks the tuple
    // and initializes arg(Arguments), which will be passed to testing routine.

    Arguments arg = setup_geqrf_arguments(GetParam());

    hipblasStatus_t status = testing_geqrf<double>(arg);

    if(status != HIPBLAS_STATUS_SUCCESS)
    {
        if(arg.M < 0 || arg.N < 0 || arg.lda < arg.M)
        {
            EXPECT_EQ(HIPBLAS_STATUS_INVALID_VALUE, status);
        }
        else
        {
            EXPECT_EQ(HIPBLAS_STATUS_SUCCESS, status);
        }
    }
}

// notice we are using vector of vector
// so each elment in xxx_range is a vector,
// ValuesIn takes each element (a vector), combines them, and feeds them to test_p
// The combinations are  { {M, N, lda, ldb}, stride_scale, batch_count }

INSTANTIATE_TEST_CASE_P(hipblasGeqrf,
                        geqrf_gtest,
                        Combine(ValuesIn(matrix_size_range),
                                ValuesIn(stride_scale_range),
                                ValuesIn(batch_count_range)));
