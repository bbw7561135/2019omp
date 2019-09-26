#include <iostream>
#include <omp.h>
using namespace std;




int main()
{

    int l = 4;
    int m = 4;
    int n = 2;

    int tid,i,j,k,counter;
    omp_set_num_threads(3);
    counter = 0;

    #pragma omp parallel for collapse(2) private(i,j,k,tid) firstprivate(counter)
    for(i=1;i<=l;i++)
        for(j=1;j<=m;j++)
            for(k=1;k<=n;k++)
                {
                    tid = omp_get_thread_num();
                    counter = counter + 1;
                    cout << "tid = " << tid <<", counter = " << counter << ", i = " << i << ", j = " << j << ", k = " << k << endl;
                }

    return 0;
}


//#include <iostream>
//#include <omp.h>
//using namespace std;
//
//
//
//
//int main()
//{
//
//    int l = 4;
//    int m = 4;
//    int n = 2;
//
//    int tid,i,j,k,counter;
//    omp_set_num_threads(3);
//    counter = 0;
//
//    #pragma omp parallel for collapse(2) private(i,j,k,tid) firstprivate(counter)
//    for(i=1;i<=l;i++)
//        for(j=1;j<=m;j++)
//            for(k=1;k<=n;k++)
//                {
//                    tid = omp_get_thread_num();
//                    counter = counter + 1;
//                    cout << "tid = " << tid <<", counter = " << counter << ", i = " << i << ", j = " << j << ", k = " << k << endl;
//                }
//
//    return 0;
//}
//tid = 0, counter = 1, i = 1, j = 1, k = 1
//tid = 2, counter = 1, i = 3, j = 4, k = 1
//tid = 2, counter = 2, i = 3, j = 4, k = 2
//tid = 2, counter = 3, i = 4, j = 1, k = 1
//tid = 2, counter = 4, i = 4, j = 1, k = 2
//tid = 2, counter = 5, i = 4, j = 2, k = 1
//tid = 2, counter = 6, i = 4, j = 2, k = 2
//tid = 2, counter = 7, i = 4, j = 3, k = 1
//tid = 2, counter = 8, i = 4, j = 3, k = 2
//tid = 2, counter = 9, i = 4, j = 4, k = 1
//tid = 2, counter = 10, i = 4, j = 4, k = 2
//
//tid = 0, counter = 2, i = 1, j = 1, k = 2
//tid = 0, counter = 3, i = 1, j = 2, k = 1
//tid = 0, counter = 4, i = 1, j = 2, k = 2
//tid = 0, counter = 5, i = 1, j = 3, k = 1
//tid = 0, counter = 6, i = 1, j = 3, k = 2
//tid = 0, counter = 7, i = 1, j = 4, k = 1
//tid = 0, counter = 8, i = 1, j = 4, k = 2
//tid = 0, counter = 9, i = 2, j = 1, k = 1
//tid = 0, counter = 10, i = 2, j = 1, k = 2
//tid = 0, counter = 11, i = 2, j = 2, k = 1
//tid = 0, counter = 12, i = 2, j = 2, k = 2
//tid = 1, counter = 1, i = 2, j = 3, k = 1
//tid = 1, counter = 2, i = 2, j = 3, k = 2
//tid = 1, counter = 3, i = 2, j = 4, k = 1
//tid = 1, counter = 4, i = 2, j = 4, k = 2
//tid = 1, counter = 5, i = 3, j = 1, k = 1
//tid = 1, counter = 6, i = 3, j = 1, k = 2
//tid = 1, counter = 7, i = 3, j = 2, k = 1
//tid = 1, counter = 8, i = 3, j = 2, k = 2
//tid = 1, counter = 9, i = 3, j = 3, k = 1
//tid = 1, counter = 10, i = 3, j = 3, k = 2
