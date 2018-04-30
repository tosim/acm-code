#include <stdio.h>
#include <math.h>

struct Point{
	double x,y;
};
int dir[4][2] = {-1,0,1,0,0,-1,0,1};

int n;
Point p[105];

double dis(Point &a,Point &b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double sum(Point tp){
	double ret = 0;
	for(int i = 0;i < n;i++){
		ret += dis(tp,p[i]);
	}
	return ret;
}

int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 0;i < n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		int tcnt = 1;
		Point s[5];
		//s[0].x = s[0].y = 5000.0;
		s[0].x = s[0].y = 0;
		double Min = 0x7fffffff;
		for(int i = 0;i < tcnt;i++){
			Point st = s[i];
			Point nt;

			double step = 1000;
			while(step > 0.1){
				int flag = 1;
				while(flag == 1){
					flag = 0;
					for(int k = 0;k < 4;k++){
						nt.x = st.x + dir[k][0] * step;
						nt.y = st.y + dir[k][1] * step;
						double tSum = sum(nt);
						if(tSum < Min){
							Min = tSum;
							st.x = nt.x;
							st.y = nt.y;
							flag = 1;
						}	
					}
				}
				step /= 2.0;
			}
		}			
		printf("%d\n",(int)(Min+0.5));
	}	
	return 0;
}
