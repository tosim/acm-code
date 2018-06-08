#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <set>
using namespace std;

const int maxn = 500 + 5;
const int INF = 0x7fffffff;

struct Node{
    int v;
    int cost;
    int start;
    int end;
    Node(int _v,int _cost,int _start,int _end):v(_v),cost(_cost),start(_start),end(_end){}
    bool operator < (const Node&b)const{
        if(start == b.start){
            if(end == b.end){
                if(cost == b.cost){
                    return v < b.v;
                }else{
                    return cost < b.cost;
                }
            }else{
                return end < b.end;
            }
        }else{
            return start < b.start;
        }
    }
};

struct CNode{
    int id;
    int now;
    CNode(int _id,int _now):id(_id),now(_now){}
};

int getTime(char str[]){
    int h = ((str[0] - '0') * 10 + (str[1] - '0')) * 2;
    int m = str[3] == '3' ? 1 : 0;
    return h + m;
}

int dis[maxn];
int vis[maxn];
vector<Node> G[maxn];


void printNode(int u,Node node){
    printf("%d %d %d %d %d\n",u,node.v,node.cost,node.start,node.end);
}

int spfa(CNode s,int n){
    queue<CNode> q;
    for(int i = 0;i < G[1].size();i++){
        q.push(CNode(1,G[1][i].start - 1));
        vis[1]++;
    }
    int isF = 1;
    while(!q.empty()){
        CNode cur = q.front();
        q.pop();
        vis[cur.id]--;

        if(cur.now + 1 >= 48){
            printf("greater then 48\n");
            continue;
        }else if(G[cur.id].size() == 0 || G[cur.id].size() == 1){
            printf("no or only one\n``");
            continue;
        }
        printf("%d next size = %lu\n",G[cur.id].size());
        for(int i = 0;i < G[cur.id].size() - 1;i++){
            Node nt = G[cur.id][i];
            printf("iterator\n");
            printNode(cur.id,nt);
            printf("dis[%d][%d] = %d\n",nt.v,nt.end,dis[nt.v][nt.end]);
            printf("now = %d,nt.start = %d\n",cur.now,nt.start);
            if(cur.now + 1 <= nt.start && dis[nt.v][nt.end] > dis[cur.id][nt.end] + nt.cost){
                printf("%d update %d,old=%d,add = %d\n",cur.id,nt.v,dis[nt.v][nt.end],nt.cost);
                dis[nt.v][nt.end] = dis[cur.id][nt.end] + nt.cost;
                if(vis[nt.v][nt.end] == 0){
                    q.push(CNode(nt.v,nt.end));
                    vis[nt.v][nt.end] = 1;
                }
            }
        }
    }
    return 1;
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char start[6],end[6];
    int x,y,c;
    set<Node> S[maxn];

    for(int i = 0;i < m;i++){
        scanf("%d%d%d%s%s",&x,&y,&c,start,end);
        int s = getTime(start);
        int e = getTime(end);
        S[x].insert(Node(y,c,s,e));
    }
    set<Node>::iterator it;
    for(int i = 1;i <= n;i++){
        for(it=S[i].begin();it!=S[i].end();it++){
            //printf("%d %d %d %d %d\n",i,(*it).v,(*it).cost,(*it).start,(*it).end);
            G[i].push_back((*it));
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < G[i].size();j++){
            printNode(i,G[i][j]);
        }
    }*/
    if(G[1].size() == 0 || G[1].size() == 1){
        printf("-1\n");
    }else{
        //printf("size = %lu\n",G[1].size());
        for(int ii = 0;ii < G[1].size()-1;ii++){
            printf("start ============= %d\n",ii);
            for(int i = 1;i <= n;i++){
                for(int j = 0;j <= 48;j++){
                    dis[i][j] = INF;
                    vis[i][j] = 0;
                }
            }
            spfa(CNode(1,G[1][ii].start),n);
        }
        /*
        int minn = INF;
        for(int i = 0;i <= 48;i++){
            if(dis[n][i] < minn){
                minn = dis[n][i];
            }
        }
        if(minn == INF){
            printf("-1\n");
        }else{
            printf("%d\n",minn);
        }*/
    }

    printf("\n");
    return 0;
}
