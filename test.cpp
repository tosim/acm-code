#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

//#define t   \"
string love[] = {
"\"\"\"\"\"        \"\"     \"\"   ",
"  \"        \"    \" \" \" ",
"  \"       \"     \"     \"",
"  \"       \"           \"",
"  \"        \"         \"",
"  \"         \"       \"",
"  \"           \"   \" ",
"  \"            \"\" ",
"\"\"\"\"\"          \"",
"end"
};
int main(){

    string tmp;
    cout<<"请输入你的名字"<<endl;
    getline(cin,tmp);

    cout<<"请输入你的性别"<<endl;
    getline(cin,tmp);

    cout<<"请输入你的专业"<<endl;
    getline(cin,tmp);

    cout<<"请输入你的年级"<<endl;
    getline(cin,tmp);

    cout<<"请输入你的年龄"<<endl;
    getline(cin,tmp);

    cout<<"冯海婧"<<endl;
    getline(cin,tmp);

    cout<<"谢谢你，让我遇到你"<<endl;
    getline(cin,tmp);

    cout<<"从第一次看到你"<<endl;
    getline(cin,tmp);

    cout<<"你的样子就在我心里"<<endl;
    getline(cin,tmp);

    cout<<"以前的我不懂得喜欢和爱"<<endl;
    getline(cin,tmp);

    cout<<"在爱情的世界里，我曾经一无所有"<<endl;
    getline(cin,tmp);

    cout<<"是你在我情感的小站里，做我的第一位来客"<<endl;
    getline(cin,tmp);

    cout<<"我想经过了几个站的你，一定累了"<<endl;
    getline(cin,tmp);

    cout<<"所以，请在我这多停留一会"<<endl;
    getline(cin,tmp);

    cout<<"当你一个人的时候，其实我一直站在你身后"<<endl;
    getline(cin,tmp);

    cout<<"如果有一天，你需要倾诉，怀抱，需要有人为你擦去泪水"<<endl;
    getline(cin,tmp);

    cout<<"你只要回过头，你就会看到我在你的身后"<<endl;
    getline(cin,tmp);

    cout<<"你曾经问我真的有一见钟情吗"<<endl;
    getline(cin,tmp);

    cout<<"虽然我也不确定之前的感受"<<endl;
    getline(cin,tmp);

    cout<<"我只知道现在我很爱你"<<endl;
    getline(cin,tmp);

    cout<<"有多爱？"<<endl;
    getline(cin,tmp);


    int i,j;

    printf("     ******       ******\n"
                "   **********   **********\n"
                  " ************* *************\n");
    for(i=0;i<3;i++){
        for(j=0;j<29;j++)
            printf("*");
        printf("\n");
    }
    for(i=0;i<7;i++){
        for(j=0;j<2*(i+1)-1;j++)
            printf(" ");
        for(j=0;j<27-i*4;j++)
            printf("*");
        printf("\n");
    }

    for(i=0;i<14;i++)//最后一个星号*与上面的规律脱节了  所以独立显示
        printf(" ");
    printf("*\n");

    return 0;
}
