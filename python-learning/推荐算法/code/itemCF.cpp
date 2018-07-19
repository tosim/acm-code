#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <utility>
#include <time.h>
#include <queue>
using namespace std;

const int maxn = 1e3 + 700;

struct Mov{
    int movId;
    int star;
    bool operator < (const Mov& b) const{
        return movId < b.movId;
    }
};
struct Node{
    int movId;
    double inter;
    Node(int a,double b):movId(a),inter(b){}
    friend bool operator > (const Node &n1, const Node &n2) {
        return n1.inter > n2.inter;
    }
};

int cmpTopK(pair<int,double> a,pair<int,double> b){
    return a.second > b.second;
}

int main(){
    clock_t startTime,endTime;
    int k = 3;
    //用户电影表格
    map<int,vector<Mov> > user_mov;
    //电影倒排表
    map<int,vector<int> > mov_user;
    map<int,map<int,int> > W;
    //数据输入
    int userId,NOVAL;
    Mov mov;
    freopen("../data/u1.base","r",stdin);
    while(scanf("%d%d%d%d",&userId,&mov.movId,&mov.star,&NOVAL) != EOF){
        user_mov[userId].push_back(mov);
        //物品用户倒排表
        mov_user[mov.movId].push_back(userId);
    }

    //对倒排表的用户排序
    map<int,vector<int> >:: iterator it;
    for(it=mov_user.begin();it!=mov_user.end();it++){
        sort(it->second.begin(),it->second.end());
        /*
        for(int i = 0;i < it->second.size();i++){
            printf("%c ",'A' + it->second[i] - 1);
        }
        printf("\n");
        */
    }

    //建立同时喜欢物品i和物品j的用户数，物品i，j的相似度为W[i][j] / sqrt(mov_user[i].size() * mov_user[j].size())
    for(it=mov_user.begin();it!=mov_user.end();it++){
        for(int i = 0;i < it->second.size();i++){
            map<int,vector<int> >::iterator jt;
            for(jt=it,jt++;jt!=mov_user.end();jt++){
                //二分查找
                vector<int>::iterator tmp = lower_bound(jt->second.begin(),jt->second.end(),it->second[i]);
                //printf("target = %c , tmp = %c\n",it->second[i] + 'A' - 1,*tmp + 'A' - 1);
                if(tmp != jt->second.end() && *tmp == it->second[i]){
                    //printf("find %c %c %c\n",'a' + it->first - 1,'A' + it->second[i]-1,'a' + jt->first-1);
                    W[it->first][jt->first]++;
                    W[jt->first][it->first]++;
                }
            }
        }
        printf("%d 电影计算完毕\n",it->first);
    }
    /*
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++){
            printf("%d ",W[i][j]);
        }
        printf("\n");
    }*/

    //为每个用户推荐
    startTime = clock();
    printf("start recommend\n");
    for(map<int,vector<Mov> >::iterator it=user_mov.begin();it!=user_mov.end();it++){
        map<int,double> recom;
        //对于用户看过的电影
        for(int i = 0;i < it->second.size();i++){
            //找到与此电影最相似的k个电影
            priority_queue<Node,vector<Node>,greater<Node> > topK;
            //vector<pair<int,double> > topK;
            map<int,int>::iterator mit;
            for(mit=W[i].begin();mit!=W[i].end();mit++){
                int flag = 1;
                for(int t = 0;t < it->second.size();t++){
                    if(mit->first == it->second[t].movId){
                        flag = 0;
                        break;
                    }
                }
                //如果此电影被用户看过
                if(flag == 0){
                    continue;
                }
                //同时看过i和j的用户数 /
                double tmp = (double)mit->second / sqrt((double)mov_user[i].size() * (double)mov_user[mit->first].size());
                if(topK.size() != k || topK.top().inter < tmp){
                    Node node(mit->first,tmp);
                    if(topK.size() != k) topK.push(node);
                    else{
                        topK.push(node);
                        topK.pop();
                    }
                    //sort(topK.begin(),topK.end(),cmpTopK);
                }
            }

            //for(int j = 0;j < topK.size();j++){
            //    printf("%d %d %lf\n",it->first,topK[j].first,topK[j].second);
            //}
            //printf("\n");

            while(!topK.empty()){
                //wij*ruj
                Node tn = topK.top();
                recom[tn.movId] = tn.inter * it->second[i].star;
                topK.pop();
            }

        }
        //得出兴趣度最高的k个电影
        printf("recommend for user %d\n",it->first);
        map<int,double>::reverse_iterator rit;
        int cnt;
        for(rit=recom.rbegin(),cnt=0;cnt < k && rit!=recom.rend();rit++,cnt++){
             printf("%d ",rit->first);
        }
        printf("\n");
    }
    endTime = clock();
    printf("total time: %.2lf s\n",(double)(endTime-startTime)/CLOCKS_PER_SEC);
    return 0;
}
