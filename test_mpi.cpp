#include <iostream>
#include <mpi.h>
 
int main(int argc, char *argv[])
{
    int numprocessors, rank, namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
 
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocessors);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Get_processor_name(processor_name, &namelen);
 
    if ( rank == 0 )
    {
        std::cout << "Processors name: " << processor_name << "\n";
    std::cout << "master (" << rank << "/" << numprocessors << ")\n";
    } else {
        std::cout << "slave  (" << rank << "/" << numprocessors << ")\n";
   }
   MPI_Finalize();
   return 0;
}

// To compile:
// mpic++ -W -Wall test_mpi.cpp -o test_mpi.o
// Tu run, just type:
// mpirun -np 4 test_mpi.o
