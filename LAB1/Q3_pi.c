#include <stdio.h>
#include <omp.h>

static long steps=100000000;

int main(){
double step=1.0/steps,sum=0;

double s=omp_get_wtime();

#pragma omp parallel for reduction(+:sum)
for(long i=0;i<steps;i++){
 double x=(i+0.5)*step;
 sum+=4.0/(1+x*x);
}

double pi=sum*step;
double e=omp_get_wtime();

printf("Pi=%lf\n",pi);
printf("Time=%f\n",e-s);
}
