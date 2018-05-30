#include <stdio.h>

const int maxn = 15 + 5;
int a[maxn];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        long long fac = 1;
        long long sum = 0;
        for(int i = n - 1,k = 1;i >= 0;i--,k++){
            int tmp = 0;
            for(int j = i + 1;j < n;j++){
                if(a[j] < a[i]){
                    tmp++;
                }
            }
            //printf("fac = %lld\n",fac);
            sum += (long long)tmp*fac;
            fac *= k;
        }
        printf("%lld\n",sum+1);
    }
    return 0;
}
