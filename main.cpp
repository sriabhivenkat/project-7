//
//  main.cpp
//  P7
//
//  Name: Sriabhinandan Venkataraman
//  UIN: 130007213
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "MatrixMultiplication.h"
using namespace std;

void benchmark(const std::vector<std::vector<int>> &a, const std::vector<std::vector<int>> &b, std::vector<std::vector<int>> &result, const int n)
{
    long double duration;
    clock_t start = std::clock();
    matrixMult1(a, b, result, n);
    clock_t end = std::clock();
    duration = (end - start) / (long double)CLOCKS_PER_SEC;
    std::cout << "Compute Time for Mult1: " << duration << " seconds.\n";

    start = std::clock();
    matrixMult2(a, b, result, n);
    end = std::clock();
    duration = (end - start) / (long double)CLOCKS_PER_SEC;
    std::cout << "Compute Time for Mult2: " << duration << " seconds.\n";

    start = std::clock();
    matrixMult3(a, b, result, n);
    end = std::clock();
    duration = (end - start) / (long double)CLOCKS_PER_SEC;
    std::cout << "Compute Time for Mult3: " << duration << " seconds.\n";

    start = std::clock();
    blockingMatrixMult(a, b, result, n, 50);
    end = std::clock();
    duration = (end - start) / (long double)CLOCKS_PER_SEC;
    std::cout << "Compute Time for Blocking Mult: " << duration << " seconds.\n";
}

int main(int argc, const char *argv[])
{

    // File Read Operation
    cout << "STARTING FILE READ OPERATION" << endl;
    cout << endl;
    ifstream file;
    string s = "Testcases/" + string(argv[1]);
    file.open(s);
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return 0;
    }
    string line;
    int n;
    int linecount = 1;
    int count = 0;
    bool isA = true;
    getline(file, line);
    istringstream iss(line);
    iss >> n;
    cout << "n = " << n << endl;
    cout << endl;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b(n, vector<int>(n));
    vector<vector<int>> result(n, vector<int>(n));
    while (getline(file, line))
    {
        if (line.length() == 0)
            continue;
        if (isA)
        {
            int count = 0;
            istringstream iss(line);
            for (int i = 0; i < n; i++)
            {
                iss >> a[linecount - 1][i];
            }
        }
        else
        {
            istringstream iss(line);
            for (int i = 0; i < n; i++)
            {
                iss >> b[count][i];
            }
            count++;
        }
        linecount++;
        if (linecount > n)
        {
            isA = false;
        }
    }
    // display matrix A
    cout << "A = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "B = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    // Matrix Mult 1 - IJK/JIK
    cout << "STARTING MATRIX MULTIPLICATION 1" << endl;
    cout << endl;
    benchmark(a, b, result, n);
    // matrixMult1(a, b, result, n);
    // cout << "Result = " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // // clear result
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         result[i][j] = 0;
    //     }
    // }
    // // Matrix Mult 2 - KIJ/IKJ
    // cout << "STARTING MATRIX MULTIPLICATION 2" << endl;
    // cout << endl;
    // matrixMult2(a, b, result, n);
    // cout << "Result = " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         result[i][j] = 0;
    //     }
    // }
    // // Matrix Mult 3 - JKI/KJI
    // cout << "STARTING MATRIX MULTIPLICATION 3" << endl;
    // cout << endl;
    // matrixMult3(a, b, result, n);
    // cout << "Result = " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         result[i][j] = 0;
    //     }
    // }
    // // Matrix Mult Blocking
    // cout << "STARTING MATRIX MULTIPLICATION BLOCKING" << endl;
    // cout << endl;
    // blockingMatrixMult(a, b, result, n, 50);
    // cout << "Result = " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // cout << "ENDING FILE READ OPERATION" << endl;
    return 0;
}
