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
		/*
		cnt = 1;		
		for(int i = 1;i <= n;i++){
			memset(vis,0,sizeof(vis));
			dfs(0,i);
			if(cnt == n){
				printf("The towers in case %d can be covered in %d frequencies.\n",_case++,i);
				break;
			}
		}
		*/
		//printf("cnt = %d\n",cnt);
		//for(int i = 0;i < n;i++) printf("clr[%d] = %d\n",i,clr[i]);
	}

	return 0;
}
