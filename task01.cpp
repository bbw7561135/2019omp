#include <iostream>
#include <omp.h>
using namespace std;




int main()
{

    omp_set_num_threads(4);
    #pragma omp parallel
    {
        cout << "A" << endl; //implicit task
        #pragma omp task //explicit task
        cout << "Race(id = " << omp_get_thread_num() << ")" << endl;
        cout << "Car" << endl;
    }
    return 0;
}
//结果是不确定的 因为线程池中的任务不一定由哪些线程执行
