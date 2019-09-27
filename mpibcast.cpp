#include "mpi.h"
#include <iostream>
#include <cmath>
using namespace std;

#define buf_size 10


int main(int argc, char **argv)
{
    int rank,numprocs,value;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);


            if(rank==0)
            {
                value = 89126;
                MPI_Bcast(&value,1,MPI_INT,0,MPI_COMM_WORLD);
                //buf,num,datatype,root,communicator
            }
        
        MPI_Bcast(&value,1,MPI_INT,0,MPI_COMM_WORLD);
        cout << "rank " << rank << "has got " << value << "from rank0" << endl;

    MPI_Finalize();

    return 0;


}































