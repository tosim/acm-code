#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//获取[0,up)的随机数
int getRandInt(int up){
    return rand()%up;
}
int maxn = 100000;
int main(){
    srand((unsigned)time(NULL));
    int n = rand()%maxn;
    printf("%d\n",n);
    int pre = 1;
    int pos = getRandInt(n);
    int out;
    for(int i = 0;i < n;i++){
        if(i != 0) printf(" ");
        int added = getRandInt(3) + 1;
        printf("%d",pre + added);
        if(i == pos) out = pre+added;
        pre = pre + added;
    }
    printf("\n");
    printf("%d\n",out);
}

