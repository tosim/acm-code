#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

const int INF = 0x7fffffff;

struct Edge{
	int v;
	int val;
	Edge(){}
	Edge(int _v,int _val):v(_v),val(_val){}
};

int r[24];
int num[24];
int N;
int vis[26];
int cnt[26];
std::vector<Edge> mp[26];//临接表记录建图，0~23代表24个节点，25代表源点start
int dis[26];

void build(int s23){
	for(int i = 0;i < 26;i++) mp[i].clear();

	for(int i = 1;i <= 23;i++){//s[i]-s[i-1] >= 0   0<i<=23
		mp[i-1].push_back(Edge(i,0));			
	}
		
	for(int i = 0;i <= 23;i++){
		mp[25].push_back(Edge(i,0));	
	}	
	//mp[25].push_back(Edge(0,0));//s[0] >= 0 => s[0] - s[start] >= 0  && s[start] = 0;
		
	for(int i = 1;i <= 23;i++){//s[i-1] - s[i] >= -num[i]      0<i<=23
		mp[i].push_back(Edge(i-1,-1*num[i]));
	}

	mp[0].push_back(Edge(25,-1*num[0]));//s[0] - s[start] <= num[0] => s[start] - s[0] >= -num[0]	

	for(int i = 8;i <= 23;i++){//s[i]-s[i-8] >= r[i]    8<=i<=23
		mp[i-8].push_back(Edge(i,r[i]));
	}
	
	for(int i = 0;i < 7;i++){
		mp[i+16].push_back(Edge(i,r[i]-s23));
	}
	
	mp[23].push_back(Edge(25,-1*s23));//s[23] - s[start] <= s23 => s[start] - s[23] >= -s23
	mp[25].push_back(Edge(23,s23));//s[23] - s[start] >= s23
}

int spfa(int s25){
	for(int i = 0;i < 26;i++) dis[i] = -1*INF;
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	std::queue<int> q;//记录待更新的点
	q.push(s25);
	vis[s25] = 1;
	cnt[s25] = 1;
	dis[s25] = 0;

	while(!q.empty()){
		int cur = q.front();
		q.pop();
		vis[cur] = 0;
		for(int i = 0;i < mp[cur].size();i++){
			int nt = mp[cur][i].v;
			int tval = mp[cur][i].val;
			if(dis[cur] + tval > dis[nt]){
				dis[nt] = dis[cur] + tval;
				if(vis[nt] != 1){
					vis[nt] = 1;
					cnt[nt]++;
					if(cnt[nt] > 25) return -1;
					q.push(nt);
				}
			}
		}	
	}
	return 1;
}

int enum_s23(){//不用二分也不会超时
	int up = N;
	int ans = -1;
	
	for(int s23 = 0;s23 <= up;s23++){
		build(s23);	
		ans = spfa(25);
		if(ans == 1){
			return s23;		
		}
	}
	return ans;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		for(int i = 0;i < 24;i++) scanf("%d",&r[i]);
		scanf("%d",&N);
		int th;
		memset(num,0,sizeof(num));
		for(int i = 0;i < N;i++){
			scanf("%d",&th);
			num[th]++;
		}

		int ans = enum_s23();
		/*
		//二分枚举s23
		int ans = -1;
		int low = 0,up = N,mid;
		while(low<=up){
			mid=(low+up)>>1;
				build(mid);
				if(spfa(25) == 1){
		              ans=mid;
		              up=mid-1;							           
				 }
		        else low=mid+1;							         
		}
		*/

		if(ans == -1){
			printf("No Solution\n");
		}else{
			printf("%d\n",ans);
		}
	}	
	return 0;
}
