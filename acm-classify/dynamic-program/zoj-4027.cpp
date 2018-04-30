#include <stdio.h>
#include <string.h>

const int maxn = 1e3 + 5;

int n;
char inc[maxn];
long long val[maxn];

int lnum,rnum;
long long cost[maxn][maxn];
long long dp[maxn][maxn];

void print(){
    for(int i = 0;i <= lnum;i++){
        for(int j = 0;j <= rnum;j++){
            printf("%lld ",cost[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void mk_cost(){
    memset(cost,0,sizeof(cost));
    lnum = rnum = 0;
    for(int i = 0;i < n;i++){
        if(inc[i] == ')'){
            rnum++;
        }
        if(inc[i] == '('){
            lnum++;
            int trnum = rnum;
            for(int j = i+1;j < n;j++){
                if(inc[j] == ')'){
                    cost[lnum][trnum+1] = cost[lnum][trnum] + val[i]*val[j];
                    trnum++;
                }
            }
        }
    }
    //print();
}

inline long long max(long long a,long long b){
    return a > b ? a : b;
}

void print_dp(){
    for(int i = 0;i <= lnum+1;i++){
        for(int j = 0;j <= rnum+1;j++){
            printf("%lld ",dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void solve(){
    memset(dp,0,sizeof(dp));
    for(int i = lnum;i >= 0;i--){
        for(int j = rnum;j >= 0;j--){
            if(j == rnum){
                dp[i][j] = cost[i][j]+dp[i+1][j];
            }else{
                dp[i][j] = max(cost[i][j] + dp[i+1][j],dp[i][j+1]);
            }
        }
    }
//    print_dp();
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",inc);
        for(int i = 0;i < n;i++){
            scanf("%lld",&val[i]);
        }
        mk_cost();
        solve();
        printf("%lld\n",dp[0][0]);
    }
    return 0;
}
