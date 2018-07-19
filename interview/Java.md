# Java

## Java内部类
### 1.静态内部类
1.静态内部类可以访问外部类的所有静态属性和静态方法，包括私有的  

### 2.成员内部类
1.不能声明静态属性和静态方法，static只能用在final的静态属性的声明上  
2.成员内部类可以访问外部类的所有方法和属性  
3.实例化内部类的时候必须用一个外部类的实例去实例化 *

## Java调用过程
1.调用父类的静态部分(静态代码块或者声明时实例化的属性，按照定义顺序执行)  
2.调用子类的静态部分(同上)  
3.调用父类的普通代码块  
4.调用父类构造方法  
5.调用子类普通代码块  
6.调用子类构造方法  


## Java单例模式（静态内部类实现）
```
public class Singleton {
    private static class LazyHolder {
        private static final Singleton INSTENCE = new Singleton();
    }

    private Singleton (){
    }

    public static final Singleton getInstance() {
        return LazyHolder.INSTENCE;
    }
}
```
