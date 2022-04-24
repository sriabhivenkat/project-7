//
//  MatrixMultiplication.cpp
//  P7
//
//  Name: Sriabhinandan Venkataraman
//  UIN: 130007213

#include "MatrixMultiplication.h"
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void matrixMult1(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result, const int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
}

void matrixMult2(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result, const int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            int r = a[i][k];
            for (int j = 0; j < n; j++)
                result[i][j] += r * b[k][j];
        }
    }
}

void matrixMult3(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result, const int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            int r = b[k][j];
            for (int i = 0; i < n; i++)
            {
                result[i][j] += a[i][k] * r;
            }
        }
    }
}

void blockingMatrixMult(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result, const int n, const int block_size)
{
    for (int jj = 0; jj < n; jj = jj + block_size)
    {
        for (int kk = 0; kk < n; kk = kk + block_size)
        {
            for (int i = 0; i < n; i = i + 1)
            {
                int minj = MIN(jj + block_size, n);
                for (int j = jj; j < minj; j = j + 1)
                {
                    int r = 0;
                    int mink = MIN(kk + block_size, n);
                    for (int k = kk; k < mink; k = k + 1)
                    {
                        r = r + a[i][k] * b[k][j];
                    };
                    result[i][j] += r;
                }
            }
        }
    }
}
