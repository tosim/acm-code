#include <stdio.h>
#include <string.h>

#define lson rt<<1,l,m
#define rson rt<<1|1,m+1,r

int sum[(10000+5)*4];

void pushUp(int rt){
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];	
}

void build(int rt,int l,int r){
	if(l == r){
		//scanf("%d",&sum[rt]);
		sum[rt] = 0;
		return;
	}
	int m = (l + r) >> 1; 
	build(lson);
	build(rson);
	pushUp(rt);
}

void update(int rt,int l,int r,int p,int add){
	if(l == r){
		sum[rt] += add;
		return;
	}
	int m = (l + r) >> 1;
	if(p <= m) update(lson,p,add);
	else update(rson,p,add);
	pushUp(rt);
}

int query(int rt,int l,int r,int L,int R){
	if(l >= L && r <= R){
		return sum[rt];
	}
	int m = (l + r) >> 1; 
	int ans = 0;
	if(L <= m) ans += query(lson,L,R);
	if(R > m) ans += query(rson,L,R);
	return ans;
}
int main(){
	//memset(sum,0,sizeof(sum));
	build(1,0,5);
	int pos,x;
	scanf("%d%d",&pos,&x);
	update(1,0,5,1,5);
	update(1,0,5,2,6);
	printf("%d\n",query(1,0,5,0,5));
	return 0;
}
