
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n,m,k;

int main() {
    scanf("%d%d%d",&n,&m,&k);
    int ans[32 + 5];
    int cnt = 0;
    while(k != 0) {
        ans[cnt++] = k & 1;
        k >>= 1;
    }
    /*for(int i = 0;i < cnt;i++){
        printf("%d",ans[i]);
    }*/
    int rel = n + m - cnt;
    for(int i = 0;i < rel;i++){
        printf("z");
    }
    for(int i = 0;i < cnt;i++){
        if(ans[i] == 0){
            printf("z");
        }else{
            printf("a");
        }
    }
    printf("\n");
    return 0;
}
