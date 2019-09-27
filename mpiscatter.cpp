#include "mpi.h"
#include <iostream>
#include <cmath>
using namespace std;

#define size 4


int main(int argc, char **argv)
{
    int rank,numprocs;
    int scnt,rcnt,src;
    double sb[size][size]={
    {1.0,2.0,3.0,4.0},
    {5.0,6.0,7.0,8.0},
    {9.0,10.0,11.0,12.0},
    {13.0,14.0,15.0,16.0}};
    double rb[size];
    
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    if(numprocs == size)
        {
            src = 1;
            scnt = size;
            rcnt = size;
            MPI_Scatter(sb,scnt,MPI_DOUBLE,rb,rcnt,MPI_DOUBLE,src,MPI_COMM_WORLD);
            cout << "rb[0-3] in rank " << rank << "is "<<rb[0]<<rb[1]<<rb[2]<<rb[3]<<endl; 
        }
    else
        {
            cout << "num of procs must be " << size << endl;
        }

    MPI_Finalize();

    return 0;


}

//rb[0-3] in rank 1is 5678
//rb[0-3] in rank 0is 1234
//rb[0-3] in rank 2is 9101112
//rb[0-3] in rank 3is 13141516






























