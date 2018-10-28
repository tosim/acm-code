#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int v;
    int c;
};

int n,m;
vector<int> V[3005];
int cmp(int a,int b) {
    return a > b;
}

long long solve(int det) {
    long long ret = 0;
    int cnt = 0;
    for(int i = 2;i <= m;i++) {
        int tmp = V[i].size();
        for(int j = 0;tmp > det && j < V[i].size();tmp--,j++) {
            ret += V[i][j];
            cnt++;
        }
    }
    if(cnt + V[1].size() > det) {
        return ret;
    } else {
        return 1e5 + 5;
    }
}

int main() {

    scanf("%d%d",&n,&m);
    int v,c;
    for(int i = 0;i < n;i++) {
        scanf("%d%d",&v,&c);
        V[v].push_back(c);
    }
    for(int i = 1;i <= m;i++) {
        sort(V[i].begin(),V[i].end());
        /*for(int j = 0;j < V[i].size();j++) {
            printf("%d ",V[i][j]);
        }
        printf("\n");*/
    }
    long long ans = 1e5 + 5;
    for(int vote = m;vote >= 0;vote--) {
        long long tmp = solve(vote);
        printf("%d = %lld\n",vote,tmp);
        if(ans > tmp) {
            ans = tmp;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
