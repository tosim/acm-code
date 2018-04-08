/*
 *poj-1009
 *行程长度编码
 * */
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

const int maxn = 1005;

struct Pix{
	int pos;
	int code;
};

int cmp(Pix a,Pix b){
	return a.pos < b.pos;
}

int width,tot,seg_num;
int seg_map[maxn][2];
Pix out_map[maxn*8];
int out_num;

int getVal(int pos){
	int p = 0,i = 0;
	while(p <= pos){
		p += seg_map[i++][1];
	}
	return seg_map[i-1][0];
}
int cal(int pos){
	int row = pos / width;
	int col = pos % width;
	int Max = -1;
	int val = getVal(pos);
	for(int i = row-1;i <= row+1;i++){
		for(int j = col-1;j <= col+1;j++){
			int tpos = i*width + j;
			if(i < 0 || j < 0 || j >= width || tpos >= tot || (i == row && j == col)) continue;//超出范围的不用计算
			int tval = abs(getVal(tpos) - val);
			if(tval > Max) Max = tval;				
		}
	}
	return Max;
}
int main(){
	while(scanf("%d",&width) && width != 0){
		out_num = seg_num = tot = 0;
		int tval,tlen;
		while(scanf("%d%d",&tval,&tlen) && (tval || tlen)){
			seg_map[seg_num][0] = tval;
			seg_map[seg_num++][1] = tlen;
			tot += tlen;
		}
		int pos = 0;
		for(int i = 0;i < seg_num;i++){
			//printf("pos = %d\n",pos);
			int row = pos / width;
			int col = pos % width;
			for(int i = row-1;i <= row+1;i++){
				for(int j = col-1;j <= col+1;j++){
					int tpos = i*width + j;
					if(i < 0 || j < 0 || j >= width || tpos >= tot) continue;//超出范围的不用计算
					//printf("tpos = %d\n",tpos);
					out_map[out_num].pos = tpos;
					out_map[out_num++].code = cal(tpos);
				}
			}
			pos += seg_map[i][1];
		}
		//计算左下角的特殊情况
		out_map[out_num].pos = tot - width;
		out_map[out_num++].code = cal(tot-width);
		
		sort(out_map,out_map+out_num,cmp);
	
		printf("%d\n",width);
		Pix pre = out_map[0];
		for(int i = 1;i < out_num;i++){
			if(out_map[i].code == pre.code) continue;
			else{
				printf("%d %d\n",pre.code,out_map[i].pos-pre.pos);
				pre = out_map[i];
			}
		}
		printf("%d %d\n",pre.code,tot - pre.pos);
		printf("0 0\n");
	}	
	printf("0\n");
	return 0;
}
