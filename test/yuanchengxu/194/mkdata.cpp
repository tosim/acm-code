#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

//获取[0,up)的随机数
long long getRandInt(long long up){
    return rand()%up;
}

long long fac(int x){
    if(x == 0 || x == 1) return 1;
    return x*fac(x-1);
}
vector<int> ans;
void decontor(long long x,int n){
    x = x - 1;
    vector<int> v;
    ans.clear();
    for(int i = 1;i <= n;i++){
        v.push_back(i);
    }
    for(int i=n-1;i>=1;i--){
        long long fac_cur = fac(i);
        long long r = x % fac_cur;//余数
        long long t = x / fac_cur;//商
        //printf("x = %lld,t = %lld,r = %lld\n",x,t,r);
        x = r;
        ans.push_back(v[t]);
        v.erase(v.begin()+t);
    }
    ans.push_back(v[0]);
}
void print(){
    for(int i = 0;i < ans.size();i++){
        if(i != 0) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
}
int maxn = 15;
int main(){
    srand((unsigned)time(NULL));
    int n = (int)getRandInt(maxn) + 1;
    printf("%d\n",n);
    long long fac_t = fac(n);
    long long tmp = getRandInt(fac_t) + 1;

    //printf("tmp = %lld\n",tmp);
    decontor(tmp,n);
    print();
}

