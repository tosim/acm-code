#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//获取[0,up)的随机数
int getRandInt(int up){
    return rand()%up;
}
int maxn = 255;
int main(){
    srand((unsigned)time(NULL));
    int n = rand()%100000;
    for(int i = 0;i < n;i++){
        printf("%c",getRandInt(26) + 'a');
    }
    printf("\n");
}

