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


//两个原因都有可能
//(1) sum1(tid) = sum1(tid) + ...
//会至少慢一个时钟周期..因为编译器要先把sum1的地址取出来，加上偏移tid，算出新地址，取出操作数，然后加上...
//尽量不要用数组
//(2)
//sum1是shared变量，为了保证cache一致性，编译器（可能）会采取一些额外操作


#include <iostream>
#include <omp.h>
using namespace std;





int main()
{


    long int numsteps = 1000000000;
    int i;
    double x,pi,step,sum;
    double stime,etime,utime;
    stime = omp_get_wtime();
    omp_set_num_threads(4);
    step = 1.0/double(numsteps);
    pi=0.0;
    sum = 0.0;
    #pragma omp parallel private(x,i) default(shared) reduction(+:sum)
    {

        #pragma omp for
        for(i=0;i<numsteps;i++)
        {
            x = (double(i)+0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
            //sum[tid] = sum[tid] + 4.0/(1.0+x*x);
        }

    }

    pi = sum*step;
    etime = omp_get_wtime();
    utime = etime -stime;
    cout << "use time " << utime << endl;
    cout << "pi is " << pi << endl;
    return 0;
}



