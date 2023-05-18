#include <stdio.h>
#include <cblas.h>

int main()
{
    double A[] = {1, 2, 0, 3, 4, 5, 0, 6, 7};
    double B[] = {8, 9, 10, 11, 12, 13};
    double alpha = 1.0;
    int M = 2, N = 3, lda = 3, ldb = 3;

    // Call trsm function from OpenBLAS
    cblas_dtrsm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans,
                CblasNonUnit, M, N, alpha, A, lda, B, ldb);

    // Print the result
    for (int i = 0; i < M * N; i++)
        printf("%f ", B[i]);
    printf("\n");

    return 0;
}
