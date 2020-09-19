/*
 * Created by Raviteja Uppalapati on 9/18/20.
 * Basic intro to the components of OpenMP - Compiler Directives, Runtime Library Routines
 */
#include <stdio.h>
#include <omp.h>

int main() {
    int n_threads, t_id;
    /* This is an OpenMP Compiler Directive that tells the compiler about how to execute. 
     * A compiler ignores this unless compiled using specific commands (e.g. gcc -fopen ...)
     * Compiler directives are used for various purposes:
     *  Spawning a parallel region
     *  Dividing blocks of code among threads
     *  Distributing loop iterations between threads
     *  Serializing sections of code
     *  Synchronization of work among threads 
     */

    #pragma omp parallel private(t_id)
    {
        /* Runtime Library Routine used to get the thread number. OpenMP has many such functions that can be used to help with processing in the parallel regions */
        t_id = omp_get_thread_num();
        printf("Hello World, This is Thread# %d\n", t_id);

        /* Another Compiler Directive */
        #pragma omp barrier
        
        if (t_id == 0) {
            /* Another Runtime Library Routine */
            n_threads = omp_get_num_threads();
            printf("Total Number of Threads# %d\n", n_threads);
        }
    }
return 0;
}
