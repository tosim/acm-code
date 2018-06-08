#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//获取[0,up)的随机数
long long getRandInt(long long up){
    return rand()%up;
}

int maxn = 999;
int main(){
    srand((unsigned)time(NULL));
    int n = (int)getRandInt(maxn) + 1;
    printf("1");
    for(int i = 0;i < n - 1;i++){
        printf("%c",'0'+(int)getRandInt(10));
    }
    printf("\n");
}

