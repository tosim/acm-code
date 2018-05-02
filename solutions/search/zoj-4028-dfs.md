# [zoj-4028](http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=4028)  

### Description
给定到每个元素的最长上升子序列值和每个元素的取值范围，求一组可能的源数组

### input  
多组输入，第一行表示测试数据T组  
对于每组测试数据，第一行为一个整数n  
接下来n个数，表示fi，最长上升子序列的值  
接下来n组，每组2个数，代表ai的取值[li,ri]  
  
### output  
对于每组输入，输出一个n整数,代表ai的值

  
### Sample Input  
```
4
6
1 2 3 2 4 3
0 5
2 4
3 3
1 2
3 5
1 5
5
1 2 1 3 1
100 200
200 300
200 400
400 500
100 500
7
1 2 3 1 1 4 2
0 3
0 3
0 3
0 3
0 3
0 3
0 3
2
1 1
1 2
2 3
```

### Sample Output  
```
1 2 3 2 5 3
200 300 200 500 200
0 1 2 0 0 3 1
2 2

```
  
### Solution
对于最长上升子序列的值，我们知道对于fi = fk 且 k是小于i的最大值，则ai <= ak （若ai > ak，则fi != fk）  
对于fi = fk + 1 ,且k 是小于i的最大值，则 ai > ak  
对于每个不等式，我们建立一条从小的元素到大的元素的有向边，对于可以等于的边，做标记  
则我们可用从入度等于0的点为起点搜索这个图，每次取最小值，当某个点的计算次数等于他的入度时（即每个进入的边都计算过时），以这个点为起点继续搜索。  
我们可以证明入度为0的点只有一个：当fi != 1 时，必定有fi = fk + 1 ，则有一条ak -> ai的边，当fi == 1 时，若i 不是最后一个fi = 1 的点，则必有fi = fk，ak <= ai （因为i不是最后一个fi=1的，所以必定存在某个这样的k），当fi=1,且i是最后一个fi=1的点，则这个点就是唯一的入度为0的点。


### Code
```
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

const int maxn = 1e5 + 2400;

struct Node{
    int to;
    int eq;
    Node(int _to,int _eq):to(_to),eq(_eq){}
};
int n;
int f[maxn];
int d[maxn];
int a[maxn];
int l[maxn];
int r[maxn];

int solved[maxn];
int in[maxn];
vector<Node> G[maxn];

void init(){
    for(int i = 0;i <= n;i++){
        G[i].clear();
        in[i] = 0;
        d[i] = -1;
        solved[i] = 0;
    }
    //memset(in,0,sizeof(in));
    //memset(solved,0,sizeof(solved));
    //memset(d,-1,sizeof(d));
    d[1] = 0;
}

void dfs(int u){
    for(int i = 0;i < G[u].size();i++){
        int v = G[u][i].to;
        int tmp = G[u][i].eq == 1 ? a[u] : a[u] + 1;
        if(tmp < l[v]){
            tmp = l[v];
        }
        if(solved[v] == 0 || a[v] < tmp){
            a[v] = tmp;
 //           printf("u = %d a[%d] = %d\n",u+1,v+1,a[v]);
        }
        solved[v]++;
        if(solved[v] == in[v]){
            dfs(v);
        }
    }
}

void print(int s){
    printf("s = %d\n",s);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < G[i].size();j++){
            printf("%d -> %d eq = %d\n",i+1,G[i][j].to+1,G[i][j].eq);
        }
    }
    printf("\n");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++){
            scanf("%d",&f[i]);
        }
        for(int i = 0;i < n;i++){
            scanf("%d%d",&l[i],&r[i]);
        }
        init();
        int s = 0;//初始化第一个点为最后一个fi=1的点
        for(int i = 1;i < n;i++){
            if(f[i] != 1){
                int u = d[f[i]-1];
                G[u].push_back(Node(i,0));  //a[i] > a[u]
                in[i]++;
            }

            if(d[f[i]] != -1){
                int v = d[f[i]];
                G[i].push_back(Node(v,1));    //a[i] <= a[k]
                in[v]++;
            }
            d[f[i]] = i;
            if(f[i] == 1){
                s = i;
            }
        }
        a[s] = l[s];
        dfs(s);
        //print(s);
        for(int i = 0;i < n;i++){
            if(i != 0) printf(" ");
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}

```



















