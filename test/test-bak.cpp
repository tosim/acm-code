#include <stdio.h>
#include <string.h>
#include <list>
#include <algorithm>
using namespace std;

int n,m,k;
int bl[105][100005];
int cnt[105];

void print(int n,int w) {
    printf("WW = %d , num = %d\n",w,n);
    for(int i = 0;i < n;i++) {
        printf("bj : %d\n",i);
        list<int>::iterator it = bl[i].begin();
        while(it!=bl[i].end()) {
            printf("%d\n",*it);
            it++;
        }
    }
}

long long cal(int w) {
    //int num = m - w + 1;
    //print(num,w);
    long long ans = 0;
    for(int j = 0;j+w <= m;j++) {
        long long tmp= 0;
        int st = 0;
        list<int>::iterator it = bl[j].begin();
        long long h;
        while(it!=bl[j].end()) {
            h = (*it) - st;
            tmp += (h * (h+1) / 2);
            st = (*it) + 1;
            it++;
        }
        h = n - st;
        tmp += (h * (h+1) / 2);
        ans += tmp;
        //printf("w = %d , j = %d , tmp = %lld\n",w,j,tmp);
    }
    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    for(int cas = 1;cas <= T;cas++) {
        for(int i = 0;i < 105;i++) {
            bl[i].clear();
        }
        scanf("%d%d%d",&n,&m,&k);
        int x,y;
        for(int i = 0;i < k;i++) {
            scanf("%d%d",&x,&y);
            bl[y-1];
        }
        for(int i = 0;i < m;i++) {
            bl[i].sort();
        }
        long long sum = 0;
        for(int w = 1;w <= m;w++) {
            long long tmp = cal(w);
            //printf("w = %d ,val = %lld\n",w,tmp);
            sum += tmp;
            for(int l = 0;l < m - w;l++) {
                list<int> tmp = bl[l+1];
                bl[l].merge(tmp);
                list<int>::iterator it,itt;
                for(it = bl[l].begin();it != bl[l].end();it++) {
                    itt = it;
                    itt++;
                    while(itt != bl[l].end() && *itt == *it) {
                        itt = bl[l].erase(itt);
                    }
                }
            }
        }
        printf("Case #%d: %lld\n",cas,sum);
    }
    return 0;
}
