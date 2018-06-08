# vector、list、map、set迭代器失效问题

## 概述
在stl容器中删除或添加元素可能会导致原来的元素迭代器失效，主要取决于容器的内部实现

## vector
1.vector内部由数组实现  
2.向vector内部插入元素时，会导致插入位置原来位置及其后面的元素的迭代器失效（这些元素都向后移动了一位）  
3.删除某一位置的元素会导致删除的元素及其之后的元素迭代器全部失效（这些元素都向前移动了一位）

## list
1.list内部由链表实现
2.向list插入元素对其他元素的迭代器无影响
3.删除list的元素时，删除的元素的迭代器失效，不影响其他元素的迭代器

## map
1.list内部由红黑树实现
2.向map插入元素对其他元素的迭代器无影响
3.删除map的元素时，删除的元素的迭代器失效，不影响其他元素的迭代器


## 测试代码
```
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <utility>

void printList(std::list<int> listM){
    std::list<int>::iterator it;
    for(it=listM.begin();it!=listM.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
}
void printVector(std::vector<int> vecM){
    std::vector<int>::iterator it;
    for(it=vecM.begin();it!=vecM.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
}
void printMap(std::map<int,int> mapM){
    std::map<int,int>::iterator it;
    for(it=mapM.begin();it!=mapM.end();it++){
        printf("%d ",it->second);
    }
    printf("\n");
}
void printSet(std::set<int> setM){
    std::set<int>::iterator it;
    for(it=setM.begin();it!=setM.end();it++){
        printf("%d ",*it);
    }
    printf("\n");
}

void testVector(){
    std::vector<int> vecM;
    vecM.push_back(1);
    vecM.push_back(1);
    vecM.push_back(2);
    vecM.push_back(2);
    vecM.push_back(3);
    vecM.push_back(3);
    std::vector<int>::iterator it;
    for(it=vecM.begin();it!=vecM.end();){
        if((*it) == 2){
            //不能用vecM.erase(it++); it++会先返回后一个元素的位置，
            //执行完erase后其后元素位置全部前移,
            //导致这个迭代器又指向了再下一个元素，最终指向了后面第二个元素
            it = vecM.erase(it);
        }else{
            it++;
        }
    }
    printVector(vecM);
}
void testList(){
    std::list<int> listM;
    listM.push_back(1);
    listM.push_back(1);
    listM.push_back(2);
    listM.push_back(2);
    listM.push_back(3);
    listM.push_back(3);
    std::list<int>::iterator it;
    for(it=listM.begin();it!=listM.end();){
        if((*it) == 2){
            it = listM.erase(it);
            //listM.erase(it++);
            //这里用listM.erase(it++); 也是可行的
            //因为it++返回后一个元素的迭代器，而list内部是链表，删除此元素不会对其后一个元素的迭代器造成影响
        }else{
            it++;
        }
    }
    printList(listM);
}
void testMap(){
    std::map<int,int> mapM;
    mapM.insert(std::pair<int,int>(1,1));
    mapM.insert(std::pair<int,int>(2,1));
    mapM.insert(std::pair<int,int>(3,2));
    mapM.insert(std::pair<int,int>(4,2));
    mapM.insert(std::pair<int,int>(5,3));
    mapM.insert(std::pair<int,int>(6,3));
    std::map<int,int>::iterator it;
    for(it=mapM.begin();it!=mapM.end();){
        if(it->second == 2){
            //it = mapM.erase(it);
            //这里不能用it = mapM.erase(it);
            //因为map.erase(iterator)返回值为void
            mapM.erase(it++);

        }else{
            it++;
        }
    }
    printMap(mapM);
}
void testSet(){
    std::set<int> setM;
    setM.insert(1);
    setM.insert(1);
    setM.insert(2);
    setM.insert(2);
    setM.insert(3);
    setM.insert(3);
    std::set<int>::iterator it;
    for(it=setM.begin();it!=setM.end();){
        if((*it) == 2){
            //it = setM.erase(it);
            //这里不能用it = setM.erase(it);
            //因为set.erase(iterator)返回值为void
            setM.erase(it++);
        }else{
            it++;
        }
    }
    printSet(setM);
}
int main(){
    testVector();
    testList();
    testMap();
    testSet();
    return 0;
}

```
