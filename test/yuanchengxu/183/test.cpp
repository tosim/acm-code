#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int maxn = 900;
int main(){
    srand((unsigned)time(NULL));
    int n = rand()%maxn + 4;
    printf("%d\n",n);
    for(int i = 0;i < n;i++){
        printf("%.1lf\n",(double)(rand()%90+5));
    }
}

