#include <stdio.h>
#include <string.h>

int vis[10];
int a[3];

void init(){
    memset(vis,0,sizeof(vis));
}

void dfs(int pos){
    if(pos == 3){
        int num = a[0]*100 + a[1]*10+a[2];
        int num2 = num*2;
        int num3 = num*3;
        int tnum2 = num2;
        int tnum3 = num3;

        if(num2 > 999 || num3 > 999){
            return;
        }
        while(num2>0){
            int tmp = num2%10;
            if(tmp == 0 || vis[tmp] == 1){
                return;
            }
            num2/=10;
        }
        while(num3>0){
            int tmp = num3%10;
            if(tmp == 0 || vis[tmp] == 1){
                return;
            }
            num3/=10;
        }
        printf("%d\n",num);
    }
    for(int i = 1;i<=9;i++){
        if(vis[i] == 0){
            a[pos] = i;
            vis[i] = 1;
            dfs(pos+1);
            vis[i] = 0;
        }
    }
}
int main(){
    init();
    dfs(0);
    return 0;
}

