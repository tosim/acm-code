#include <stdio.h>
#include <vector>

long long factor(int n){
    if(n == 1 || n == 0) return 1;
    return n * factor(n-1);
}
long long contor(int a[],int n){
    long long fac = 1;
    long long sum = 0;
    for(int i=n-1,k=1;i>=0;i--,k++){
        int cnt = 0;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i]){
                cnt++;
            }
        }
        //printf("cnt = %d,fac=%lld\n",cnt,fac);
        sum += cnt * fac;
        fac *= k;
    }
    return sum;
}

std::vector<int> decontor(long long x,int n){
    x -= 1;
    std::vector<int> v;
    std::vector<int> ans;
    for(int i = 1;i <= n;i++){
        v.push_back(i);
    }
    for(int i=n;i>=1;i--){
        long long fac = factor(i-1);
        long long r = x % fac;
        long long t = x / fac;
        //printf("x = %lld,t = %lld,r = %lld\n",x,t,r);
        //printf("add %d\n",v[t]);
        x = r;
        ans.push_back(v[t]);    //说明此数是剩下数里面第t大的   (从0开始)
        v.erase(v.begin()+t);   //删除此数;
    }
    return ans;
}
void print(std::vector<int> v){
    for(int i = 0;i < v.size();i++){
        printf("%d",v[i]);
    }
    printf("\n");
}
int main(){
    int a[] = {2,3,1};
    long long x = contor(a,3);
    std::vector<int> ans = decontor(4,3);
    print(ans);
    printf("%lld\n",x+1);
    return 0;
}
