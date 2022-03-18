#include <iostream>
#include <climits>
#include <time.h>
#include "tsp.h"
using namespace std;

int main()
{
    double best_len,average_len,worst_len;
    int loop_counter;

    srand(time(NULL));
    point_dist();

    best_len=LONG_MAX;
    average_len=worst_len=0;
    init();
    SA();
	best_len = D_bestpath.length;
    
    cout<<"best: "<<best_len<<endl;

    return 0;
}
