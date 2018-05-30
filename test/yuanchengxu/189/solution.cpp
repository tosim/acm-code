#include <stdio.h>

const int maxn = 100000 + 5;

int a[maxn];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        int s,e,x;
        int sum = 0;
        int maxx = -0x7fffffff;
        for(int i = 0;i < n;i++){
            if(sum < 0){
                x = i;
                sum = a[i];
            }else{
                sum += a[i];
            }
            if(sum > maxx){
                maxx = sum;
                s = x;
                e = i;
            }
        }
        printf("%d\n",maxx);
        printf("%d %d\n",s+1,e+1);
        for(int i = s;i <= e;i++){
            if(i != s) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
