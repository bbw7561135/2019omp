#include <iostream>
#include <omp.h>
using namespace std;

int fib(int n)
{
    int fib_result;
    int i,j;
    if(n < 2)
        fib_result = n;
    else
    {
        #pragma omp task shared(i) firstprivate(n)
        i = fib(n-1);
        #pragma omp task shared(j) firstprivate(n)
        j = fib(n-2);
        #pragma omp taskwait
        fib_result = i + j;
    }
    return fib_result;
}



int main()
{

    int n = 16, result;
    omp_set_dynamic(0); //0 is close 1 is open
    omp_set_num_threads(4);
    #pragma omp parallel shared(n)
    {
        result = fib(n);
        #pragma omp single
            cout << "fib(" << n << ") = " << result << endl;
    }
    return 0;
}


//fib(16)=987
