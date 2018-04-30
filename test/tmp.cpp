#include <stdio.h>
#include <stdlib.h>

const int maxn = 5e5;
const int MAX = 1e9;

void print(){
    printf("1\n");
    printf("%d %d\n",maxn,maxn);

    for(int i = 0;i < maxn;i++){
        if(i != 0) printf(" ");
        printf("%d",rand() % (MAX -2) + 2);
    }
    printf("\n");
    for(int i = 0;i < maxn;i++){
        if(i != 0) printf(" ");
        printf("%d",rand() % (MAX-2) + 2);
    }
    printf("\n");
}

int main(){

    print();
    return 0;
}
