#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//获取[0,up)的随机数
int getRandInt(int up){
    return rand()%up;
}

char name[25] = "test";

int maxn = 15;
int main(){
    srand((unsigned)time(NULL));
    int n = (int)getRandInt(100) + 1;
    printf("%d\n",n);
    for(int i = 0;i < n;i++){
        printf("%d ",getRandInt(101));
        printf("%s_%d\n",name,i);
    }
}

