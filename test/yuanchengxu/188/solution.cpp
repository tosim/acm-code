#include <stdio.h>
#include <list>

void test(){
    std::list<int> listM;
    listM.push_back(2);
    listM.push_back(2);
    listM.push_back(2);
    listM.push_back(4);
    listM.push_back(5);
    listM.push_back(6);

    std::list<int>::iterator it;
    for(it=listM.end(),it--;it!=listM.begin();){
        if(*it == 2){
            listM.erase(it--);
        }else{
            it--;
        }
    }
    if(*it == 2){
        listM.erase(it);
    }
    for(it=listM.begin();it!=listM.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
}
int main(){
    int n;
    //test();
    while(scanf("%d",&n) != EOF){
        std::list<int> listM;
        for(int i = 1;i <= n;i++){
            listM.push_back(i);
        }
        int dir = 1;
        while(listM.size() != 2){
            if(dir == 1){
                std::list<int>::iterator it;
                int c;
                for(it=listM.begin(),c=1;it!=listM.end();c++){
                    if(c==3){
                        //printf("erase %d\n",*it);
                        it = listM.erase(it);
                        c = 0;
                    }else{
                        it++;
                    }
                }
            }else{
                std::list<int>::iterator it;
                int c;
                for(it=listM.end(),it--,c=1;it!=listM.begin();c++){
                    if(c==3){
                        //printf("erase %d\n",*it);
                        listM.erase(it--);
                        c = 0;
                    }else{
                        it--;
                    }
                }
                if(c==3){
                    //printf("erase %d\n",*it);
                    listM.erase(it);
                    c = 0;
                }
            }
            dir ^= 1;
        }
        if(dir == 1){
            printf("%d\n",listM.front());
        }else{
            printf("%d\n",listM.back());
        }
    }
    return 0;
}
