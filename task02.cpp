#include <iostream>
#include <omp.h>
using namespace std;




int main()
{

    omp_set_num_threads(4);
    #pragma omp parallel
    {
        #pragma omp single //single保证创建任务的线程只有一个
        //创建任务后 所有线程都可以从任务池拿任务
        { //任务池有2个任务 两个线程各完成一个
            //没有single的话 会有8个输出
             #pragma omp task
             cout << "Task 1 from thread " << omp_get_thread_num() << endl;

             #pragma omp task
             cout << "Task 2 from thread " << omp_get_thread_num() << endl;
        }
    }
    return 0;
}


