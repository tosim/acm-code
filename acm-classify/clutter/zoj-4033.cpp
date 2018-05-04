#include <stdio.h>

const int maxn = 1e5 + 5;

int n;
char s[maxn];
void print(){
    int i = 0;
    if(n%4 == 3){
        i = 0;
        if(s[i] == '0'){
            printf("1");
        }else{
            printf("3");
        }
        if(s[i+1] == '0'){
            printf("1");
        }else{
            printf("3");
        }
        if(s[i+2] == '0'){
            printf("2");
        }else{
            printf("4");
        }
        i = 3;
    }
    for(;i + 3 < n;i+=4){
        for(int j = 0;j < 4;j++){
            if(j == 0 || j == 3){
                if(s[i+j] == '0'){
                    printf("1");
                }else{
                    printf("3");
                }
            }else{
                if(s[i+j] == '0'){
                    printf("2");
                }else{
                    printf("4");
                }
            }
        }
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",s);
        if(n%4 == 0 || n%4 == 3){
            print();
        }else{
            printf("-1\n");
        }
    }
    return 0;
}
