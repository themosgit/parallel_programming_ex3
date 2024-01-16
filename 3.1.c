#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "timer.h"
#include <time.h>


long long int monte_carloP(long long int my_first_i, long long int my_last_i );
long long int monte_carloS(long long int throws);

int main(int argc, char *argv[]) {
    long long int result_velh;
    long long int local_result_velh;
    long long int plhuos_ripsewn = 10000000;
    MPI_Init(&argc, &argv);

    int my_rank, comm_sz;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

    srand(time(NULL) + my_rank);

    long long int my_n = plhuos_ripsewn / comm_sz;
    long long int my_first_i = my_n * my_rank;
    long long int my_last_i = my_first_i + my_n;
    local_result_velh = monte_carloP(my_first_i, my_last_i);

    double start, finish;
    GET_TIME(start);
         MPI_Reduce(&local_result_velh, &result_velh, 1, MPI_LONG_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    if(my_rank == 0){
        GET_TIME(finish);
        printf("velh %lld\n", result_velh);
        printf("Parallel Elapsed time = %e seconds\n", finish - start);
        printf("pi: %lf\n", (double) 4 * result_velh / plhuos_ripsewn);
    }
    MPI_Finalize();
    /*
    GET_TIME(start);
    monte_carloS(plhuos_ripsewn);
    GET_TIME(finish) 
    printf("Serial Elapsed time = %e seconds\n", finish - start);
    */
    return 0;
}

long long int monte_carloP(long long int my_first_i, long long int my_last_i) {
    int velh = 0;

    for (long long int i = my_first_i; i < my_last_i; i++) {
        double x = (rand() % 2000 - 1000) / 1000.0;
        double y = (rand() % 2000 - 1000) / 1000.0;
        double tetragwno = x * x + y * y;
        if (tetragwno <= 1) {
            velh++;
        }
    }

    return velh;

}

long long int monte_carloS(long long int throws){
    int velh = 0; 
    srand(time(NULL));
    for (int i = 0; i < throws; i++){
        double x = (rand() % 2000 - 1000) / 1000.0;
        double y = (rand() % 2000 - 1000) / 1000.0;
        double tetragwno= x*x + y*y;
        if(tetragwno <= 1) {
            velh++;
        }
    }

    return velh;
}