#include <stdio.h>
#include <string.h>

int cnt[10005];

int main(){
    int n;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    int m_max = -1;
    int x;
    for(int i = 0;i < n;i++){
        scanf("%d",&x);
        cnt[x]++;
        if(x > m_max){
            m_max = x;
        }
    }
    //printf("max = %d\n",m_max);
    for(int i = 0;i <= m_max;i++){
       printf("%d\n",cnt[i]);
    }
    return 0;
}
