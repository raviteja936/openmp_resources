#include <omp.h>
#include <stdio.h>
#define CHUNKSIZE 1
#define N 10

void main() {
    int n_threads, t_id, chunk, i, j;
    int a[N][N], b[N][N], c[N][N];

    /* Some initializations */
    for (i=0; i < N; i++)
        for (j=0; j < N; j++) {
            a[i][j] = i;
            b[i][j] = j;
            c[i][j] = 0;
        }
            
    chunk = CHUNKSIZE;

    #pragma omp parallel shared(a,b,c,n_threads,chunk) private(i,t_id)
    {
        t_id = omp_get_thread_num();
        if (t_id == 0) {
            n_threads = omp_get_num_threads();
            printf("Number of threads = %d\n", n_threads);
        }
        
        #pragma omp barrier
        
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Section 1 is worked by Thread %d\n", t_id);
            }
            #pragma omp section
            {
                printf("Section 2 is worked by Thread %d\n", t_id);
            }
        }
        
        #pragma omp barrier
        
        #pragma omp for schedule(static,chunk)
        for (i=0; i<N; i++) {
            for (j=0; j<N; j++) {
                c[i][j] = a[i][j] * b[i][j];
            }
            printf("Thread %d: Row %d of C ready\n",t_id, i);
        }

    }  /* end of parallel section */
}
