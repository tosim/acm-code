#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void cal_next(char *str, int *next, int len)
{
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1;//k初始化为-1
    for (int q = 1; q <= len-1; q++)
    {
        while (k > -1 && str[k + 1] != str[q])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。
        {
            k = next[k];//往前回溯
        }
        if (str[k + 1] == str[q])//如果相同，k++
        {
            k = k + 1;
        }
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q]
    }
}

int KMP(char *str, int slen, char *ptr, int plen,int* next)
{
    //int *next = new int[plen];
    cal_next(ptr, next, plen);//计算next数组
    int k = -1;
    for (int i = 0; i < slen; i++)
    {
        while (k >-1&& ptr[k + 1] != str[i])//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配）
            k = next[k];//往前回溯
        if (ptr[k + 1] == str[i])
            k = k + 1;
        if (k == plen-1)//说明k移动到ptr的最末端
        {
            //cout << "在位置" << i-plen+1<< endl;
            //k = -1;//重新初始化，寻找下一个
            //i = i - plen + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠），感谢评论中同学指出错误。
            return i-plen+1;//返回相应的位置
        }
    }
    return -1;  
}

int main()
{
    int a[100005],b[100005],next[100005];
    char t[100005];
    int m,n;
    cin>>m>>n;
    cin>>t;
    if(m>n){
        m=m%n;
    }
    int ls=-1,le=-1;
    int cnt = 0;
    while(m!=0){
        m=m*10;
        a[cnt]=m/n;
        m=m%n;
        b[cnt]=m;
        for(int h=0;h<cnt;h++){
            if(b[h]==m){
                ls = h + 1;
                le = cnt;
				m=0;
                break;
            }
        }
        cnt++;
    }
    if(ls == -1){
        ls = le = cnt;
        a[cnt++] = 0;
    }
    //cout<<s<<"."; //输出整数部分
    /*cout<<"ls = "<<ls<<",le = "<<le<<endl;
    for(int j=0;j<cnt;j++){
        cout<<a[j];
    }
    cout<<endl;
    cout<<"cnt="<<cnt<<endl;
    */
    //==========
    char str[1000005];
	for(int i = 0;i < ls;i++){
        str[i] = '0' + a[i];
    }
    int loopLen = cnt - ls;
    int tt = strlen(t) - ls > 0 ? strlen(t) - ls : 0;
    int k = tt / loopLen + 2;
    int cur = ls;
    //printf("k = %d,ls = %d,le = %d\n",k,ls,le);
    for(int i = 0;i < k;i++){
        for(int p = ls;p <= le;p++){
            str[cur++] = '0' + a[p];
        }
    }
    str[cur++] = '\0';
    //printf("%s\n",str);
    //printf("%s\n",t);
    //printf("strlen = %d\n",strlen(str));
    int ans = KMP(str,strlen(str),t,strlen(t),next);
    if(ans == -1){
        printf("-1\n");
    }else{
        printf("%d\n",ans+1);
    }
    return 0;
}

