#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
/*
struct Node{
    int val;
    int pos;
    bool operator < (const Node& b)const{
        return pos < b.pos;
    }
};*/

int vis[105];
int ans[105];
int cnt;

void init(){
    for(int i = 10;i <= 100;i++){
        vis[i] = 0;
    }
    cnt = 0;
}

int main(){
    int n;
    scanf("%d",&n);
    init();
    int x;
    for(int i = 0;i < n;i++){
        scanf("%d",&x);
        if(vis[x] == 0){
            ans[cnt++] = x;
            vis[x] = 1;
        }
    }
    for(int i = 0;i < cnt;i++){
        if(i != 0) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
