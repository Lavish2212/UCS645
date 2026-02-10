#include <omp.h>
#include <stdio.h>

#define N 500

double grid[N][N], newgrid[N][N];

int main() {

    double start = omp_get_wtime();

    #pragma omp parallel for collapse(2)
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            newgrid[i][j] =
                0.25 * (grid[i - 1][j] + grid[i + 1][j] +
                        grid[i][j - 1] + grid[i][j + 1]);
        }
    }

    double end = omp_get_wtime();
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}
