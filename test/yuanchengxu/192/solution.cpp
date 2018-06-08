#include <stdio.h>
#include <string.h>

const int maxn = 1000 + 5;

int main(){
    char str[maxn];
    scanf("%s",str);
    int len = strlen(str);
    int i;
    for(i = 0;i < len % 3;i++){
        printf("%c",str[i]);
    }
    if(len % 3 != 0){
        printf(",");
    }
    for(int c=0;i < len;i++,c++){
        if(c == 3){
            printf(",");
            c = 0;
        }
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
