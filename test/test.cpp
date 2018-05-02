#include <stdio.h>
#include <algorithm>

using namespace std;
int a[] = {1,4,8,16,18};

void test(){
    printf("%ld\n",lower_bound(a,a+5,1) - a);
    printf("%ld\n",upper_bound(a,a+5,17) - a - 1);
}
int main(){
    test();
    return 0;
}
