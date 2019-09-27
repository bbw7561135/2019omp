#include "mpi.h"
#include <iostream>
#include <cmath>
using namespace std;

#define buf_size 10


int main(int argc, char **argv)
{
    int myid,numprocs,other,sb[buf_size],rb[buf_size];
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);

    for(int i=0;i<buf_size;i++)
    {
        sb[i] = myid + 1;
    }

    if(myid==0) other = 1;
    if(myid==1) other = 0;

    if(myid==0)
    {
        
        cout << "id " << myid << "of " << numprocs << " total process try sending" << endl;
        MPI_Send(sb,buf_size,MPI_INT,other,1,MPI_COMM_WORLD);
        //buf,size,datatype,target,tag,communicator
        cout << "id " << myid << "of " << numprocs << " total process try receving" << endl;
        MPI_Recv(rb,buf_size,MPI_INT,other,1,MPI_COMM_WORLD,&status);
    }

    if(myid==1)
    {
        cout << "id " << myid << "of " << numprocs << " total process try receving" << endl;
        MPI_Recv(rb,buf_size,MPI_INT,other,1,MPI_COMM_WORLD,&status);
        cout << "id " << myid << "of " << numprocs << " total process try sending" << endl;
        MPI_Send(sb,buf_size,MPI_INT,other,1,MPI_COMM_WORLD);
    
    
    }

    cout <<  "Hello World from process " << myid << "of total " << numprocs << "its rb[9] is " << rb[9] << endl;
    MPI_Finalize();

    return 0;


}


//id 1of 2 total process try receving
//id 0of 2 total process try sending
//id 0of 2 total process try receving
//id 1of 2 total process try sending
//Hello World from process 1of total 2its rb[9] is 1
//Hello World from process 0of total 2its rb[9] is 2



























