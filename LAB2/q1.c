#include <omp.h>
#include <stdio.h>
#include <math.h>

#define N 1000

int main() {
    double x[N], force[N];

    for (int i = 0; i < N; i++) {
        x[i] = i * 0.01;
        force[i] = 0.0;
    }

    double start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double r = x[i] - x[j];
            double f = 1.0 / (r * r + 1e-9);

            #pragma omp atomic
            force[i] += f;
        }
    }

    double end = omp_get_wtime();
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}
