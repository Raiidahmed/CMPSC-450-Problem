///////////////////////////////////////////////////////////////////////
//
// CMPSC450 
//
// Benchmark Template
// 
// Author: Mr. Seisler
//
// compile line:
// g++ -o bench_tmp benchmark_template.cpp -O3
//
///////////////////////////////////////////////////////////////////////
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///////////////////////////////////////////////////////////////////////
// A simple subroutine to get the current wall time.
//
// Assigns wcTime the value of time in seconds
///////////////////////////////////////////////////////////////////////
void get_walltime(double* wcTime) {

     struct timeval tp;

     gettimeofday(&tp, NULL);

     *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);

}

///////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{

	// Initialize stuff here...
	double d_S,d_E,min,max;
    int R,m,steps;
    double* A;
    double* B;
    double* C;
    double* D;
    double MFLOPS;
    double diff;
    char str1[1];
    steps = 100;
    int N[steps];  
    m = 0; 
    min = log(10);
    max = log(1E7);
    diff = (max-min)/steps;

    for(double l = min; l < max; l += diff){
        N[m] = exp(l);
        m++;
    }

    for(int k = 0; k < steps; k++){

        R = 1E9/N[k];

        A = (double*) malloc(N[k] * sizeof(double));
        B = (double*) malloc(N[k] * sizeof(double));
        C = (double*) malloc(N[k] * sizeof(double));
        D = (double*) malloc(N[k] * sizeof(double));

        for(int i = 0; i < N[k]; i++){
            A[i] = 0E0;
            B[i] = 1E0;
            C[i] = 2E0;
            D[i] = 3E0;
        }

        get_walltime(&d_S);  // get start time

        // place test code here
        for(int j = 0; j < R; j++){
            for(int i = 0; i < N[k]; i++){
                A[i] = B[i] + C[i] * D[i];
            }
            if(A[2] < 0){
                printf("dummy");
                }
        }

        get_walltime(&d_E); // get end time stamp

        // report results here
        printf("%d\n", k);
        printf("%d\n", N[k]);
        printf("%f\n", d_E - d_S);
        MFLOPS = R*N[k]*2E0/((d_E-d_S)*1E6);
        printf("%f\n", MFLOPS);
        printf("\n");

        // perform cleanup here
        free(A);
        free(B);
        free(C);
        free(D);

        
    }

    scanf("%s", str1);

	return 0;
}

