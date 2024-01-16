#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "timer.h"
#include <time.h>

double* Mat_vect_mult(double local_A[], double x[], int local_n, int n);

void Mat_vect_multS(double A[], double x[], double y[], int n);

int main(int argc, char *argv[]) {

int n = 1000;

double* A = malloc(n * n * sizeof(double));
double* x = malloc(n * sizeof(double));
double* Y = malloc(n * sizeof(double));

/*MPI_Init(&argc, &argv);

int my_rank, comm_sz;
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

srand(time(NULL) + my_rank);

int local_n = n / comm_sz;
double* local_a = malloc(local_n * n * sizeof(double));
double* local_y = malloc(local_n * sizeof(double));

double start, finish;
GET_TIME(start);

if (my_rank == 0) {
    for (int i = 0; i < n; i++) {
        x[i] = rand();
        for (int j = 0; j < n; j++) {
            A[i * n + j] = rand();
        }
    }
    MPI_Scatter(A, local_n * n, MPI_DOUBLE, local_a, local_n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
} else {
    MPI_Scatter(NULL, local_n * n, MPI_DOUBLE, local_a, local_n * n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
}

MPI_Bcast(x, n, MPI_DOUBLE, 0, MPI_COMM_WORLD);
local_y = Mat_vect_mult(local_a, x, local_n, n);

MPI_Gather(local_y, local_n, MPI_DOUBLE, Y, local_n, MPI_DOUBLE, 0, MPI_COMM_WORLD);

GET_TIME(finish);

if (my_rank == 0) printf("\nElapsed time = %e seconds\n", finish - start);

free(local_a);
free(local_y);
MPI_Finalize();
*/

double start, finish;
GET_TIME(start);

for (int i = 0; i < n; i++) {
    x[i] = rand();
    for (int j = 0; j < n; j++) {
        A[i * n + j] = rand();
    }
}

Mat_vect_multS(A, x, Y, n);
GET_TIME(finish);
printf("\nElapsed time = %e seconds\n", finish - start);

free(A);
free(x);
free(Y);



return 0;
}  


double* Mat_vect_mult(double local_A[], double x[], int local_n, int n) {
    
    double* local_y = malloc(local_n * sizeof(double));
    for (int local_i = 0; local_i < local_n; local_i++) {
        local_y[local_i] = 0.0;
        for (int j = 0; j < n; j++) {
            local_y[local_i] += local_A[local_i * n + j] * x[j];
        }
    }
    return local_y;
}

void Mat_vect_multS(double A[], double x[], double y[], int n){
    for(int i = 0; i < n; i++) {
        y[i] = 0.0;
        for(int j = 0; j < n; j++)
            y[i] += A[i * n + j] * x[j];
    }
}