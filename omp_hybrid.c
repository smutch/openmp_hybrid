#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <mpi.h>
#include <omp.h>
#include <sched.h>


int main(int argc, char *argv[])
{
  int i_rank, n_rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &i_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &n_rank); 

  char name[MPI_MAX_PROCESSOR_NAME];
  int proc_name_len;
  MPI_Get_processor_name(name, &proc_name_len);

  int n_max = omp_get_max_threads();
  int cpu_id = sched_getcpu();

  if (i_rank == 1)
    omp_set_num_threads(2);
  else
    omp_set_num_threads(1);

  int n_avail = omp_get_num_procs();

#pragma omp parallel
  {
    int i_thread = omp_get_thread_num();
    printf("Hello world from rank %d (%s:%d):thread %d (%d avail; %d max)...\n", i_rank, name, cpu_id, i_thread, n_avail, n_max);
  }

  MPI_Finalize();

  return 0;
}
