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
    int m,steps;
    int R;
    double* A;
    double* B;
    double* C;
    double* D;
    double MFLOPS;
    double diff;
    double randC;
    double randomNumber;
    int L1_Cache_Size, L2_Cache_Size, L3_Cache_Size;
    char str1[1];
    L1_Cache_Size = 10000;
    L2_Cache_Size = 80000;
    L3_Cache_Size = 8E8;
    unsigned long long int e;
    //steps = 100; // Uncomment to test on a logarithimic scale from min to max 
    steps = 3; //Uncomment to test N at a single certain value
    int N[steps];  
    //m = 0; // Uncomment to test on a logarithimic scale from min to max 
    //min = log(10); // Uncomment to test on a logarithimic scale from min to max 
    //max = log(1E7); // Uncomment to test on a logarithimic scale from min to max 
    //diff = (max-min)/steps; // Uncomment to test on a logarithimic scale from min to max
    N[0] = L1_Cache_Size;  //Uncomment to test N at a single certain value
    N[1] = L2_Cache_Size;
    N[2] = L3_Cache_Size;
    //for(double l = min; l < max; l += diff){ // Uncomment loop to test on a logarithimic scale from min to max 
        //N[m] = exp(l);
        //m++;
    //}
    

    for(int k = 0; k < steps; k++){

        R = 1E9/N[k];

        A = (double*) malloc(N[k] * sizeof(double));
        B = (double*) malloc(N[k] * sizeof(double));
        C = (double*) malloc(N[k] * sizeof(double));
        D = (double*) malloc(N[k] * sizeof(double));

        for(int i = 0; i < N[k]; i++){
            //randomNumber = rand(); //Uncomment to test with random values between (-1,1) in C
            //randC = ((randomNumber/32767)*2)-1E0; //Uncomment to test with random values between (-1,1) in C
            A[i] = 0E0;
            B[i] = 1E0;
            C[i] = 2E0; //Uncomment to test with only positive values in C
            //C[i] = -2E0; //Uncomment to test with only negative values in C
            //C[i] = randC;
            D[i] = 3E0;
        }

        get_walltime(&d_S);  // get start time

        // place test code here
        for(int j = 0; j < R; j++){
            for(int i = 0; i < N[k]; i++){
                if (C[i] < 0){
                    A[i] = B[i] - C[i] * D[i];
                } else {
                    A[i] = B[i] + C[i] * D[i];
                }
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

