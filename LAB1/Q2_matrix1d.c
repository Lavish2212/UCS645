#include <stdio.h>
#include <omp.h>
#define N 500

double A[N][N],B[N][N],C[N][N];

int main(){
for(int i=0;i<N;i++)
 for(int j=0;j<N;j++){
  A[i][j]=1; B[i][j]=1; C[i][j]=0;
 }

double s=omp_get_wtime();

#pragma omp parallel for
for(int i=0;i<N;i++)
 for(int j=0;j<N;j++)
  for(int k=0;k<N;k++)
   C[i][j]+=A[i][k]*B[k][j];

double e=omp_get_wtime();
printf("1D Time=%f\n",e-s);
}
