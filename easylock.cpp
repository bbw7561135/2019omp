#include <iostream>
#include <omp.h>
using namespace std;




int main()
{

    int m = 5;
    int tid,i;
    omp_lock_t lck;

    omp_set_num_threads(3);
    omp_init_lock(&lck);
    #pragma omp parallel for private(tid,i) shared(lck)
    for(i=0;i<m;i++)
    {
        tid = omp_get_thread_num();
        omp_set_lock(&lck);
        cout << "id = " << tid << " i = " << i << endl;
        omp_unset_lock(&lck);

    }
    omp_destroy_lock(&lck);
    return 0;
}

//id = 0 i = 0
//id = 1 i = 2
//id = 2 i = 4
//id = 0 i = 1
//id = 1 i = 3
