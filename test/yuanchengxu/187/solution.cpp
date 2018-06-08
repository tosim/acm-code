#include <stdio.h>

int month[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int year[2] = {365,366};
char week[7][10] = {
    "Sunday", "Monday","Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int typeOfYear(int y){
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        int day = n % 7;
        int y,m;
        for(y = 2000;;y++){
            int type = typeOfYear(y);
            if(n > year[type]){
                n -= year[type];
            }else{
                break;
            }
        }
        int type = typeOfYear(y);
        for(m = 1;;m++){
            int sub = month[m];
            if(m == 2 && type == 1) sub++;
            if(n >= sub){
                n -= sub;
            }else{
                break;
            }
        }
        printf("%4d-%02d-%02d %s\n",y,m,n+1,week[(day+6)%7]);
    }
    return 0;
}
