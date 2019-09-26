#include <iostream>
#include <omp.h>
using namespace std;




int main()
{

    long int i,j;
    long int max1 = 100000;
    double start_time,end_time,time;
    double a,b,c;

    omp_set_num_threads(4);
    a=0.0;
    b=0.0;
    c=0.0;

    #pragma omp parallel private(i,j) default(shared)
    {
        start_time = omp_get_wtime();
        #pragma omp for reduction(+:a) schedule(static)
        for(i=1;i<max1;i++)
            for(j=i;j<max1;j++)
                a=a+(double)(j)/(double)(j+i);
        end_time = omp_get_wtime();
        time = end_time - start_time;
        #pragma omp single
        cout << "static use time(ms): " << time <<'\t'<<"a = " << a << endl;

        start_time = omp_get_wtime();
        #pragma omp for reduction(+:b) schedule(dynamic)
        for(i=1;i<max1;i++)
            for(j=i;j<max1;j++)
                b=b+(double)(j)/(double)(j+i);
        end_time = omp_get_wtime();
        time = end_time - start_time;
        #pragma omp single
        cout << "dynamic use time(ms): " << time <<'\t'<<"b = " << b << endl;

        start_time = omp_get_wtime();
        #pragma omp for reduction(+:c) schedule(guided)
        for(i=1;i<max1;i++)
            for(j=i;j<max1;j++)
                c=c+(double)(j)/(double)(j+i);
        end_time = omp_get_wtime();
        time = end_time - start_time;
        #pragma omp single
        cout << "guided use time(ms): " << time <<'\t'<<"c = " << c << endl;
    }

    return 0;
}


//static use time(ms): 10.151     a = 3.46568e+009
//dynamic use time(ms): 4.912     b = 3.46568e+009
//guided use time(ms): 7.93       c = 3.46568e+009

