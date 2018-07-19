#include <iostream>
using namespace std;

class Animal{
protected:
    string m_strName;
public:
    Animal(){
        cout<<"Animal Constructor called"<<endl;
    }
    void setAnimalName(string strName){
        this->m_strName = strName;
    }
    virtual void talk() = 0;//纯虚函数，子类实现
    virtual ~Animal(){//虚析构函数，保证多态时能够调用到子类的析构函数，安全释放内存
        cout<<"Animal destructor called"<<endl;
    }
};

class Cat:public Animal{
public:
    Cat(){
        cout<<"Cat Constructor called.My number is 你的学号"<<endl;
        this->m_strName = "cat";
    }
    void talk(){
        cout<<this->m_strName<<":miao miao miao"<<endl;
    }
    ~Cat(){
        cout<<"Cat destructor called."<<endl;
    }
};

class Dog:public Animal{
public:
    Dog(){
        cout<<"Dog Constructor called.My number is 你的学号"<<endl;
        this->m_strName = "dog";
    }
    void talk(){
        cout<<this->m_strName<<":wang wang wang"<<endl;
    }
    ~Dog(){
        cout<<"Cat destructor called."<<endl;
    }
};

class Main{
public:
    Animal* createAnimal(int type){
        if(type == 1){
            return new Cat();
        }else{
            return new Dog();
        }
    }

    void letTalk(Animal* animal){
        animal->talk();
    }

    void test(){
        Animal* animal1 = createAnimal(1);
        Animal* animal2 = createAnimal(2);
        letTalk(animal1);
        letTalk(animal2);
        delete animal1;
        delete animal2;
    }
};
int main(){
    Main mm;
    mm.test();
    return 0;
}
