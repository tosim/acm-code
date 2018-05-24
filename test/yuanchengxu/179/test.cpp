#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand((unsigned)time(NULL));
    int n = 10;
    printf("%d\n",n);
    for(int i = 0;i < n;i++){
        if(i != 0) printf(" ");
        printf("%d",rand()%90+10);
    }
    printf("\n");
}

