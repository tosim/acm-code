# [Sicily-1039](https://vjudge.net/contest/220690#problem/E)  

### Description  
给定n个塔的坐标，两个塔的距离<=20的表示这两个塔相邻，相邻的两个塔发射的频率不能相同，问这n个塔最少需要用到多少个频率  
  
### input    
多组测试数据  
每组第一行为n，表示塔的个数  
接下来n对数，代表每个塔的坐标  
  
### output   
按如下格式输出所需的最少的频率数

  
### Sample Input  
```
5
0 0 5 7.5 1 -3 10.75 -20.1 12.01 -22
6
0 1 19 0 38 1 38 21 19 22 0 21
0
```

### Sample Output  
```
The towers in case 1 can be covered in 3 frequencies.
The towers in case 2 can be covered in 2 frequencies.
```
  
### Solution
根据塔的坐标先建立无向图，距离<=20的建边，接下来就是图的最少染色问题，即相邻的点不能染相同的颜色，问所用的最少颜色数。

![](https://github.com/tosim/acm-code/raw/master/solutions/resources/sicily-1039-img1.gif)  

数据量较小，直接深搜

1.标记0号点颜色为1  
2.搜索相邻的节点nt
3.尝试对nt染成颜色i
4.若nt可以染成颜色i，则以nt为源点继续搜索，否则重复3
5.直到所有的点搜索完毕，返回所用到的最大颜色ans

### Code
```
#include <stdio.h>
#include <utility>
#include <math.h>
#include <string.h>

int n;
int mp[13][13];
std::pair<double,double> p[13];
int cnt;
int clr[13];
int vis[13];

int check(int v,int color){
	if(clr[v] != 0) return 0;
	for(int i = 0;i < n;i++){
		if(mp[v][i] == 1 && clr[i] == color){
			return 0;
		}
	}
	return 1;
}
void dfs(int s){
	vis[s] = 1;
	for(int i = 0;i < n;i++){
		if(mp[s][i] == 1 && vis[i] == 0){
			for(int cc = 1;cc <= n;cc++){
				if(check(i,cc)){
					if(cc > cnt) cnt = cc;
					clr[i] = cc;
				}
			}
			dfs(i);
		}	
	}
}
int main(){	
	int _case = 1;
	while(scanf("%d",&n) && n){
		double x,y;
		for(int i = 0;i < n;i++){
			scanf("%lf%lf",&x,&y);
			p[i].first = x;
			p[i].second = y;
		}
		memset(mp,0,sizeof(mp));
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				double dis = (p[i].first-p[j].first) * (p[i].first-p[j].first) + (p[i].second-p[j].second) * (p[i].second-p[j].second);
				if(dis <= 400.0){
					mp[i][j] = mp[j][i] = 1;
				}
			}
		} 
		memset(clr,0,sizeof(clr));
		memset(vis,0,sizeof(vis));
		clr[0] = 1;
		cnt = 1;
		dfs(0);
		printf("The towers in case %d can be covered in %d frequencies.\n",_case++,cnt);
		//printf("cnt = %d\n",cnt);
		//for(int i = 0;i < n;i++) printf("clr[%d] = %d\n",i,clr[i]);
	}

	return 0;
}


```




























