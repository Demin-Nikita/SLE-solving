#include <iostream>
#include <math.h>
#include <stdio.h>
#include "cmath.h"

#define mdim 8
#define INDX(i, j)  (i) * mdim + (j)

void transpose(double* a, int n, double* at);
void matrixComposition(double* l, double* r, double* result, int nw, int nh);
int getSphericalNorm(double* x, int n);

int main() {
    static double cond;
    double det;
    int pivot[mdim], i, flag;

    int n = 8;
    static double p_range[] = { 1.0, 0.1, 0.01, 0.0001, 0.000001 };
    static double b[] = { 4*p_range[0] - 175, 133, 110, 112, 17, 32, 13, -18};
    static double b2[] = { 4 * p_range[0] - 175, 133, 110, 112, 17, 32, 13, -18 };
    static double a[] =
    { p_range[0] - 29,    6,   -6,   -4,   -3,   -8,   -5,    5,
                    6,  -13,   -3,    5,    4,    3,    1,    7,
                    5,   -5,   -1,    7,    2,    0,    7,    1,
                    5,   -5,    5,    6,    4,   -7,    4,    0,
                    4,    4,    7,   -4,    9,   -8,   -8,   -4,
                   -4,    5,   -4,    1,    0,   12,    0,    6,
                   -3,   -2,   -4,    2,   -8,   -3,   16,    4,
                    7,    5,    0,    2,    0,   -6,    8,  -12 };
    static double at[mdim * mdim];
    static double a2[mdim * mdim];
    int pivot2[mdim];

    for (double p : p_range) {
        printf("-----------------------------------------------------\n");
        printf("Resault with p = %f\n", p);
        printf("-----------------------------------------------------\n");
        a[0] = p - 29;
        b[0] = 4 * p - 175;

        transpose(a, mdim, at);
        matrixComposition(at, a, a2, mdim, mdim);
        matrixComposition(at, b, b2, mdim, 1);

        printf("Solution of the original system:\n");

        decomp(n, mdim, a, &cond, pivot, &flag);
        printf("%s\n", cmathmsg(DECOMP_C, flag));

        if (flag == 0) {
            solve(n, mdim, a, b, pivot);

            printf("Solution =          [");
            for (i = 0; i < n; i++) {
                printf("%6.3f, ", b[i] * a[8 * 4 + i]);
            }
            printf("]\n");

            printf("Condition number =  %e\n", cond);

            det = pivot[n - 1];
            for (i = 0; i < n; i++) {
                det = det * a[INDX(i, i)];
            }
            printf("Determinant  =      %f\n\n", det);
        }

        printf("Solution of the system obtained after the Gauss transformation:\n");

        decomp(n, mdim, a2, &cond, pivot2, &flag);
        printf("%s\n", cmathmsg(DECOMP_C, flag));

        if (flag == 0) {
            solve(n, mdim, a2, b2, pivot2);

            printf("Solution =          [");
            for (i = 0; i < n; i++) {
                printf("%6.3f, ", b[i] * a[8 * 4 + i]);
            }
            printf("]\n");

            printf("Condition number =  %e\n", cond);

            det = pivot2[n - 1];
            for (i = 0; i < n; i++) {
                det = det * a2[INDX(i, i)];
            }
            printf("Determinant  =      %f\n\n", det);
        }

        for (int i = 0; i < n; i++) {
            b2[i] = b[i] - b2[i];
        }
        printf("A posteriori assessment: %e\n\n", getSphericalNorm(b2, n) / getSphericalNorm(b, n));
    }
    return (0);
}


void transpose(double* a, int n, double* at) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            at[INDX(j, i)] = a[INDX(i, j)];
        }
    }
}

void matrixComposition(double* l, double* r, double* result, int nw, int nh) {
    for (int i = 0; i < nh; i++) {
        for (int j = 0; j < nw; j++) {
            result[INDX(i, j)] = 0;
            for (int k = 0; k < nw; k++) {
                result[INDX(i, j)] += (r[INDX(i, k)] * r[INDX(k, j)]);
            }
        }
    }
}

int getSphericalNorm(double* x, int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result += x[i] * x[i];
    }
    return result;
}