#include <iostream>
#include <omp.h>
using namespace std;





int main()
{


    long int numsteps = 1000000000;
    int i,tid;
    double x,pi,step,tempsum;
    double sum[4]={0.0};
    double stime,etime,utime;
    stime = omp_get_wtime();
    omp_set_num_threads(4);
    step = 1.0/double(numsteps);
    pi=0.0;
    #pragma omp parallel private(x,i,tid,tempsum) default(shared)
    {
        tid = omp_get_thread_num();
        sum[tid] = 0.0;
        tempsum = 0.0;
        #pragma omp for
        for(i=0;i<numsteps;i++)
        {
            x = (double(i)+0.5)*step;
            tempsum = tempsum + 4.0/(1.0+x*x); //不要用数组 很慢 循环里面
            //sum[tid] = sum[tid] + 4.0/(1.0+x*x);
        }
        sum[tid] = tempsum ;
    }

    for(i=0;i<4;i++)
        pi = pi + step*sum[i];
    etime = omp_get_wtime();
    utime = etime -stime;
    cout << "use time " << utime << endl;
    cout << "pi is " << pi << endl;
    return 0;
}


