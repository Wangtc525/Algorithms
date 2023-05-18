#include <stdio.h>
#include <stdlib.h>
void checkData(double *arr, double data)
{
    for (int i = 9; i >= 0; i--)
    {
        if (data >= i * 0.1)
        {
            arr[i]++;
            break;
        }
    }
}
int main(int argc, char **argv)
{
    FILE *fp = fopen(argv[1], "r");
    double sum = 0;
    double nnzL[20] = {0};
    double nnzU[20] = {0};
    double nnzA[20] = {0};
    char buf[1024];
    while (!feof(fp))
    {
        sum++;
        double l, u, a;
        fscanf(fp, "%lf,%lf,%lf", &l, &u, &a);
        checkData(nnzL, l);
        checkData(nnzU, u);
        checkData(nnzA, a);
    }

    fclose(fp);
    for (int i = 0; i < 10; i++)
    {
        printf("%lf,%lf,%lf\n", nnzL[i] / sum * 100, nnzU[i] / sum * 100, nnzA[i] / sum * 100);
    }
    return 0;
}