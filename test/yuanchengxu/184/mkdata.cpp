#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//获取[0,up)的随机数
int getRandInt(int up){
    return rand()%up;
}
int maxn = 10;
int main(){
    srand((unsigned)time(NULL));
    int n = rand()%maxn;
    printf("%d\n",n);
    for(int i = 0;i < n;i++){
        if(i != 0) printf(" ");
        printf("%d",getRandInt(200) - 100);
    }
    printf("\n");
}

