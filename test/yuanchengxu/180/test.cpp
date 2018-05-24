#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){
    srand((unsigned)time(NULL));
    int n = rand()%4000 + 10;
    printf("%d %d\n",n,n-5);
}

