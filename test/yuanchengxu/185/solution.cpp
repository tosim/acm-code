#include <stdio.h>

const int maxn = 1e5 + 5;

int a[maxn];

int main(){
    int n,key;
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&key);

        int l = 0,r = n - 1;
        int cnt = 0,pos;
        while(l < r){
            int m = (l + r) >> 1;
            cnt++;
            if(a[m] > key){
                r = m - 1;
            }else if(a[m] < key){
                l = m + 1;
            }else{
                pos = m;
                break;
            }
        }
        printf("%d %d\n",pos+1,cnt);
    }
    return 0;
}
