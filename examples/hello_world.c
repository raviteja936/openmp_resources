/*
 * Created by Raviteja Uppalapati on 9/18/20.
 * Basic intro to the components of OpenMP - Compiler Directives, Runtime Library Routines, Environment Variables
 */
#include <stdio.h>
#include <omp.h>

int main() {
    int n_threads, t_id;
    #pragma omp parallel private(t_id)
    {
        t_id = omp_get_thread_num();
        printf("Hello World, This is Thread# %d\n", t_id);
        #pragma omp barrier
        if (t_id == 0) {
            n_threads = omp_get_num_threads();
            printf("Total Number of Threads# %d\n", n_threads);
        }
    }
return 0;
}
