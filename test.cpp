#include <stdio.h>
#include <string.h>

char mp[105][105];
char sg[105];

void solve(int len){
    int col = strlen(sg) - 1;
    int maxx[105];
    int cnt,sum;
    int num[105][105];
    memset(maxx,0,sizeof(maxx));
    int maxi[105];
    for(int i = 0;i < len;i++){
        cnt = 0;
        sum = 0;
        for(int j = 0;mp[i][j] != '\0';j++){
            if(mp[i][j] != '&' && mp[i][j] != 10){
                sum++;
            }else{
                num[i][cnt] = sum;
                if(maxx[cnt] < sum){
                    maxx[cnt] = sum;
                    maxi[cnt] = i;
                }
                cnt++;
                sum = 0;
            }
        }
    }
    int mark[105];
    mark[0] = 0;
    int s = 0;
    for(int i = 0;i < col;i++){
        s += maxx[i] + 3;
        mark[i+1]= s;
    }
    for(int kk = 0;kk <= mark[col];kk++){
        if(kk == 0 || kk == mark[col]) printf("@");
        else printf("-");
    }
    printf("\n");
    for(int i = 0;i < len;i++){
        printf("| ");

        int j = 0;
        for(int cur = 0;cur < col;cur++){
            if(num[i][cur] == maxx[cur]){
                for(;mp[i][j] != '&' && mp[i][j] != 10;j++){
                    printf("%c",mp[i][j]);
                }
                j++;
                printf(" |");
                if(cur != col - 1){
                    printf(" ");
                }
                continue;
            }
            if(sg[cur] == '<'){
                for(;mp[i][j] != '&' && mp[i][j] != 10;j++){
                    printf("%c",mp[i][j]);
                }
                j++;
                for(int kk = 0;kk < maxx[cur]-num[i][cur];kk++){
                    printf(" ");
                }
            }else if(sg[cur] == '>'){
                for(int kk = 0;kk < maxx[cur]-num[i][cur];kk++){
                    printf(" ");
                }
                for(;mp[i][j] != '&' && mp[i][j] != 10;j++){
                    printf("%c",mp[i][j]);
                }
                j++;
            }else{
                int le = (maxx[cur]-num[i][cur]) / 2;
                for(int kk = 0;kk < le;kk++){
                    printf(" ");
                }
                for(;mp[i][j] != '&' && mp[i][j] != 10;j++){
                    printf("%c",mp[i][j]);
                }
                for(int kk = 0;kk < maxx[cur]-num[i][cur] - le;kk++){
                    printf(" ");
                }
                j++;
            }
            printf(" |");
            if(cur != col - 1){
                printf(" ");
            }
        }
        printf("\n");
        if(i == 0){
            int cc = 0;
            for(int kk = 0;kk <= mark[col];kk++){
                if(mark[cc] == kk){
                    if(kk == 0 || kk == mark[col]){
                        printf("|");
                    }else if(i == 0){
                        printf("+");
                    }else{
                        printf("|");
                    }
                    cc++;
                }else{
                    printf("-");
                }
            }
            printf("\n");
        }

    }
    for(int kk = 0;kk <= mark[col];kk++){
        if(kk == 0 || kk == mark[col]) printf("@");
        else printf("-");
    }
    printf("\n");
}
int main(){
    fgets(sg,105,stdin);
    int i = 0;
    while(fgets(mp[i],105,stdin)){
        if(mp[i][0] == '*' || mp[i][0] == '>' || mp[i][0] == '<' || mp[i][0] == '='){
            solve(i);
            if(mp[i][0] == '*') break;
            strcpy(sg,mp[i]);
            i = 0;
            continue;
        }
        i++;
    }
    return 0;
}
