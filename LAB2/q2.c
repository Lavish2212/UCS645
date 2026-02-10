#include <omp.h>
#include <stdio.h>

#define N 500

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    static int H[N][N];

    double start = omp_get_wtime();

    for (int d = 1; d < 2 * N; d++) {
        #pragma omp parallel for
        for (int i = 1; i < N; i++) {
            int j = d - i;
            if (j > 0 && j < N) {
                H[i][j] = max(0,
                    max(H[i-1][j-1] + 1,
                        max(H[i-1][j], H[i][j-1])));
            }
        }
    }

    double end = omp_get_wtime();
    printf("Execution Time: %f seconds\n", end - start);

    return 0;
}
