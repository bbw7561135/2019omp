#include <iostream>
#include <omp.h>
using namespace std;




int main()
{

    long int i,sum,product;
    int x[10];

    omp_set_num_threads(3);

    sum = 0;
    product = 1;
    #pragma omp parallel for private(i) shared(x,sum,product)
    for(i=0;i<10;i++)
    {
        x[i] = i + 1;
        #pragma omp atomic
            sum = sum + x[i];
        #pragma omp atomic
            product = product * x[i];

        cout  << "x[" << i << "] = " << x[i] << ", sum = " << sum << ", product = " << product << endl;
    }
        cout  <<"sum = " << sum << ", product = " << product << endl;
    return 0;
}


//x[0] = 1, sum = 6, product = 5x[7] = 8, sum = 14
//x[1] = 2, sum = 16, product = 80
//, product = 40
//x[8] = 9, sum = 28, product = 2160
//x[9] = 10, sum = 38, product = 21600
//x[4] = 5, sum = 5, product = 5
//x[5] = 6, sum = 44, product = 129600
//x[6] = 7, sum = 51, product = 907200
//x[2] = 3, sum = 19, product = 240
//x[3] = 4, sum = 55, product = 3628800
//sum = 55, product = 3628800
