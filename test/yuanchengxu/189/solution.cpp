#include <stdio.h>
#include <string.h>

struct Node{
    int pos;
    int cnt;
};

Node a[26];

int main(){
    char x;
    int maxx = 0,pos;
    int cnt[26];
    memset(cnt,0,sizeof(cnt));
    int k = 0;
    while(x = getchar()){
        if(x == '\n' || x == EOF){
            break;
        }
        int idx = x - 'a';
        a[idx].cnt++;
        if(a[idx].cnt == 1){
            a[idx].pos = k;
        }
        k++;
    }
    int minn = -1;
    char minnchar;
    for(int i = 0;i < 26;i++){
        if(a[i].cnt == 1){
            if(minn == -1 || a[i].pos < minn){
                minn = a[i].pos;
                minnchar = 'a' + i;
            }
        }
    }
    if(minn == -1){
        printf("no\n");
    }else{
        printf("%c\n",minnchar);
    }
    return 0;
}
