#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int maxn = 9000;
int main(){
    srand((unsigned)time(NULL));
    int n = rand()%maxn + 10;
    printf("%d\n",n);
    for(int i = 0;i < n;i++){
        if(i != 0) printf(" ");
        printf("%d",rand()%maxn+10);
    }
    printf("\n");
}

