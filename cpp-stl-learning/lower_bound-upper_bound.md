# STL 学习之lower_bound和upper_bound
 
## 头文件
在**algorithm**中包含lower_bound和upper_bound

## 参数
begin，end，key
数组或不定长数组的起始和结束未知及要查询的key

## 返回值
返回一个迭代器，指向这个key

## 在升序的容器中
lower_bound 返回第一个 >= key 的元素的迭代器
upper_bound 返回最后一个 <= key 的元素的***后一个元素***的迭代其

## 在降序的容器中
lower_bound 返回第一个 <= key 的元素的迭代器
upper_bound 返回最后一个 >= key 的元素的***后一个元素***的迭代其

## 理解
也就是说，lower_bound和upper_bound在没找到等于key的元素时，返回的元素尽量往数组的中间靠

