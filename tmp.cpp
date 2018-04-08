#include<stdio.h>
#include<list>
int width;
struct node{
	int i,ii;
	int j,jj;
	int value;
	int beg,len;
}temp;
int print(struct node &x)
{
	printf("%d,%d,%d,%d %d,%d:%d\n",x.i,x.j,x.ii,x.jj,x.beg,x.len,x.value);
}
std::list<struct node> in,ans;
int len;
int print(std::list<struct node> &x)
{
	int i,j,k;
	k=0;
	std::list<struct node>::iterator it;
		printf("%d\n",x.size());
	for(it=x.begin();it!=x.end();it++)
	{
		for(j=0;j<it->len;j++)
		{
	//		printf("%d,%d,%d,%d:%d\t",it->i,it->j,it->ii,it->jj,it->value);
			printf("%d\t",it->value);
			if((++k)%width==0) printf("\n");
			k%=width;
		}
	}
}
bool check(struct node &x,int i,int j)
{
	if(j<0||j>=width) return false;
	if(i<0||i>=len/width) return false;
	
	if(i<x.i||i>x.ii) return false;
	if(i==x.i&&j<x.j) return false;
	if(i==x.ii&&j>=x.jj) return false;
//	printf("check ",i,j);
	return true;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
inline int abs(int a){return a>0?a:-a;}
int run()
{
	int i,j,k,l,m;
	std::list<struct node>::iterator it[3][3];
	for(i=0;i<9;i++) it[0][i]=in.begin();
	k=0;
	while(k<len)
	{
//		scanf("%d",&i);
//		printf("asd%d,%d\n",k,len);
		m=1024024024;l=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				while((it[i][j]!=in.end())&&(it[i][j]->beg+it[i][j]->len-1<k+width*(i-1)+j-1)) it[i][j]++;
			}
		}
		if(k/width==0) m=width-k;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(it[i][j]==in.end()) continue;
				if(!check(*it[i][j],k/width+i-1,k%width+j-1)) continue;
//				print(*it[i][j]);
				m=min(m,it[i][j]->beg+it[i][j]->len-((k+width*(i-1)+j-1)));
				l=max(l,abs(it[i][j]->value-it[1][1]->value));
			}
//		printf("aaa%d ",m);
		}
	//	printf("qwe ");
		if(ans.size()&&ans.back().value==l) ans.back().len+=m;
		else
		{
			temp.len=m;
			temp.value=l;
			ans.push_back(temp);
		}
		k+=m;
	}
}

int main()
{
	int i,j,k;
	while(~scanf("%d",&width))
	{
		if(width==0) break;
		k=0;
		ans.clear();
		in.clear();
		while(~scanf("%d %d",&i,&j))
		{
			if((i|j)==0) break;
			temp.value=i;
			temp.len=j;
			temp.beg=k;
			temp.i=k/width;
			temp.j=k%width;
			k+=j;
			temp.ii=k/width;
			temp.jj=k%width;
	//		printf("asd %d",i|j); 
			in.push_back(temp);
		}
		len=k;
	//	print(in);
		run();
		std::list<struct node>::iterator it;
		printf("%d\n",width);
		for(it=ans.begin();it!=ans.end();it++)
		{
			printf("%d %d\n",it->value,it->len);
		}
		
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}
