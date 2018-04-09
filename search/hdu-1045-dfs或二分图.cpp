#include <stdio.h>
#include <string.h>

int n;
char mp[5][5];

int ans;

int dir[4][2] = {-1,0,1,0,0,-1,0,1};
int vis[5][5];

int is_ok(int ni,int nj){
	for(int i = ni-1;i >= 0;i--){
		if(mp[i][nj] == 'X') break;
		if(mp[i][nj] == 'Y') return 0;
	}
	for(int i = ni+1;i < n;i++){
		if(mp[i][nj] == 'X') break;
		if(mp[i][nj] == 'Y') return 0;
	}
	for(int j = nj-1;j >= 0;j--){
		if(mp[ni][j] == 'X') break;
		if(mp[ni][j] == 'Y') return 0;
	}
	for(int j = nj+1;j < n;j++){
		if(mp[ni][j] == 'X') break;
		if(mp[ni][j] == 'Y') return 0;
	}
	return 1;
}
void dfs(int i,int j,int num){
	if(num > ans){
		ans = num;
	}
	
	for(int d = 0;d < 4;d++){
		int ni = i + dir[d][0];
		int nj = j + dir[d][1];
		if(ni >= 0 && nj >= 0 && ni < n && nj < n && vis[ni][nj] != 1){
			char ori = mp[ni][nj];
			if(mp[ni][nj] == '.'&& is_ok(ni,nj)){
				vis[ni][nj] = 1;
				mp[ni][nj] = 'Y';
				dfs(ni,nj,num+1);
			}
			vis[ni][nj] = 1;
			mp[ni][nj] = ori;
			dfs(ni,nj,num);
			vis[ni][nj] = 0;//回溯
		}
	}

}
int main(){
	
	while(scanf("%d",&n) && n){
		for(int i = 0;i < n;i++) scanf("%s",mp[i]);
		ans = 0;	
		vis[0][0] = 1;
		dfs(0,0,0);
		if(mp[0][0] == '.'){
			mp[0][0] = 'Y';
			dfs(0,0,1);	
		}
		printf("%d\n",ans);
	}
	return 0;
}
