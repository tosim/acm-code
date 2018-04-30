#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 5e5 + 1;
const long long MOD = 1e9;

long long sum[maxn][31];
int a[maxn];
map<long long,int> px;

int n,m;
void init(){
    //memset(sum,0,sizeof(sum));//不需要初始化，而且写了就超时
    px.clear();
}

int find_left(long long x){
    int l = 0,r = n - 1;
    while(l < r){
        int m = (l + r) >> 1;
        if(a[m] > x){
            r = m;
        }else if(a[m] < x){
            l = m + 1;
        }else{
            l = m + 1;
        }
    }
    if(a[l] > x){
        return l;
    }else{
        return -1;
    }
}

int find_right(long long x){
    int l = 0,r = n - 1;
    while(l + 1 < r){
        int m = (l + r) >> 1;
        if(a[m] > x){
            r = m - 1;
        }else if(a[m] < x){
            l = m;
        }else{
            l = m;
        }
    }
    if(a[r] <= x){
        return r;
    }else if(a[l] <= x){
        return l;
    }else{
        return -1;
    }
}

void test_find(){
    n = 5;
    a[0] = 2;
    a[1] = 5;
    a[2] = 10;
    a[3] = 15;
    a[4] = 16;
    printf("l = %d , r = %d\n\n",find_left(16),find_right(18));
}
int main(){
    //test_find();
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(int i = 0;i < n;i++){
            for(int k = 1;k <= 30;k++){
                if(i == 0){
                    sum[i][k] = a[i]/k;
                }else{
                    sum[i][k] = sum[i-1][k] + a[i] / k;
                }
            }
        }
        //print_sumik();
        int p;
        long long ans = 0;
        for(int i = 1;i <= m;i++){
            scanf("%d",&p);
            //printf("cal p = %d\n",p);
            if(px.find(p) != px.end()){
                //printf("p = %d has been caled\n",p);
                ans = (ans + (long long)i*px[p]%MOD)%MOD;
                continue;
            }
            long long pk = p;
            long long eans = 0;
            //long long pre = pk;//这里特别注意，因为pk乘上去会超longlong，必须用pre记录pk的前一个合法值
            //因为当p^k-1大于1e9的时候，也就是条件不成立的时候,p^k可能大于1e18
            for(int k = 1;/*pre < a[n-1]*/;k++/*,pre = pk*/,pk *= p){
                long long lx = pk / p;
                long long rx = pk;

                int l = find_left(lx);
                if(l == -1){
                    continue;
                }
                int r = find_right(rx);
                if(r == -1){
                    continue;
                }
                if(l > r){
                    continue;
                }
                long long tmp;
                if(l == 0) tmp = sum[r][k];
                else tmp = sum[r][k] - sum[l-1][k];
                eans = (eans + tmp%MOD)%MOD;
                //printf("p = %d,k = %d,search (%lld,%lld]\n",p,k,lx,rx);
                //printf("l = %d,r = %d,add %lld\n\n",l,r,tmp);
                if(pk >= a[n-1]) break;
            }
            px[p] = eans;
            ans = (ans + (long long)i*eans%MOD)%MOD;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
