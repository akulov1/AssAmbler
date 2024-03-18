#include <iostream>
#include <omp.h>

using namespace std;

void random_matrix(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 11;
}

int main()
{
    srand(time(NULL));
    int n1 = 1000;
    int m1 = 500;
    int n2 = 500;
    int m2 = 1200;

    int** matrix1;
    int** matrix2;

    matrix1 = new int* [n1];
    for (int i = 0; i < n1; i++)
        matrix1[i] = new int[m1];

    matrix2 = new int* [n2];
    for (int i = 0; i < n2; i++)
        matrix2[i] = new int[m2];

    random_matrix(matrix1,n1,m1);
    random_matrix(matrix2,n2,m2);
    int** result;
    result = new int* [n1];
    for (int i = 0; i < n1; i++)
        result[i] = new int[m2];
    int threadsNum = 2;
    omp_set_num_threads(threadsNum);
    int i, j, k;
#pragma omp parallel for shared(matrix1, matrix2, result) private(i, j, k)
    for(i = 0; i<n1; i++)
        for (j = 0; j < m2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < m1; k++)
                result[i][j] += (matrix1[i][k] * matrix2[k][j]);
        }
    for (i = n1-10; i < n1; i++) {
        cout << endl;
        for (j = m2-10; j < m2; j++)
            cout << result[i][j] << " ";
    }
}