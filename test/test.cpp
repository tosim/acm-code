#include <stdio.h>

int main(){
    long long ans = 1;
    for(int i = 2;i <= 30;i++){
        ans *= i;
    }
    printf("%lld\n",ans);
    return 0;
}
