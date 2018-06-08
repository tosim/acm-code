#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d",&n);
    int x;
    char name[25];
    int maxx = -1;
    char ans[25];
    for(int i = 0;i < n;i++){
        scanf("%d %s",&x,name);
        if(maxx == -1 || x > maxx){
            maxx = x;
            strcpy(ans,name);
        }
        //printf("x = %d name = %s\n",x,name);
    }
    printf("%s\n",ans);
    return 0;
}
