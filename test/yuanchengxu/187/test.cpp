#include <iostream>
#include <iomanip>
using namespace std;
int leap(int);
char weekday[7][10] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };//已知2000年1月1日是星期六  一定要细心别拼错了，一开始就把Wednesday拼错了，提交出错总是查不到原因……
int year[2] = { 365, 366 };
int month[2][12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//分别是平年的月份天数和闰年的月份天数。耐心、细心！注意和year顺序对应
int main(){
    int days=0, dayofweek;
    int i = 0, j = 0;
    while (cin >> days) {
        if (days == -1) break;
        dayofweek = days % 7;// 取模得到星期几
        for (i = 2000; days >= year[leap(i)]; i++){//核能预警，非战斗人员迅速撤退……如果天数大于一年的天数就减去一年，直到小于365或366
            days -= year[leap(i)];
        }
        for (j = 0; days >= month[leap(i)][j]; j++)//与上面同理，减掉每个月的天数，直到小于当月天数
        {
            days -= month[leap(i)][j];
        }
        cout << i << "-" <<setfill('0')<< setw(2)<<j + 1 << "-" <<setfill('0')<<setw(2)<< days + 1 << " " << weekday[dayofweek] << endl;//按照格式输出，注意月份+1（因为j从0开始），天数+1，可以自己代入特殊值推算一下
    }//注意输出样例的09，06，需要设置域宽并填充0.这个方法是百度来的，记住就好。头文件iomanip.h
    return 0;
}
int leap(int i){                      //判断闰年与否，注意和year对应
    if ((i % 4 != 0) ||( i % 100 ==0 && i % 400 != 0))  return 0;//0是平年
    else return 1;//1是闰年
}
