#-*-coding:utf-8-*-
from numpy import *

'''
输入：向量A，向量B
输出：两个向量的欧式距离
描述：计算两个向量的欧式距离
'''
def distEclud(vecA, vecB):
    return sqrt(sum(power(vecA - vecB, 2)))


'''
输入：数据集、K
输出：包含K个随机质心（centroid）的集合
描述：为给定数据集生成一个包含K个随机质心的集合
'''
def randCent(dataSet, k):
    n = shape(dataSet)[1]          #得到数据集的列数
    centroids = mat(zeros((k,n)))  #得到一个K*N的空矩阵
    for j in range(n):             #对于每一列（对于每一个数据维度）
        minJ = min(dataSet[:,j])   #得到最小值
        rangeJ = float(max(dataSet[:,j]) - minJ) #得到当前列的范围
        centroids[:,j] = mat(minJ + rangeJ * random.rand(k,1)) #在最小值和最大值之间取值
                                   #random模块的rand(a,b)函数返回a行b列的随机数（范围：0-1）
                                   #在这里mat()加不加都无所谓，但是为了避免赋值右边的变量类
                                   #型不是matrix，还是加上比较好
    return centroids

'''
输入：数据集，k,计算向量间距离的函数名，随机生成k个随机质心的函数名
输出：包含质心的集合，簇分配结果矩阵
描述：kmeans算法实现
'''
def kMeans(dataSet, k, distMeas=distEclud, createCent=randCent):
    m = shape(dataSet)[0]             #数据集的行数，即数据的个数
    clusterAssment = mat(zeros((m,2)))#簇分配结果矩阵
                                      #第一列储存簇索引值
                                      #第二列储存数据与对应质心的误差
    centroids = createCent(dataSet, k)#先随机生成k个随机质心的集合
    clusterChanged = True
    while clusterChanged:             #当任意一个点的簇分配结果改变时
        clusterChanged = False
        for i in range(m):            #对数据集中的每一个数据
            minDist = inf; minIndex = -1
            for j in range(k):        #对于每一质心
                distJI = distMeas(centroids[j,:],dataSet[i,:])#得到数据与质心间的距离
                if distJI < minDist:  #更新最小值
                    minDist = distJI; minIndex = j
            #若该点的簇分配结果改变
            if clusterAssment[i,0] != minIndex: clusterChanged = True
            clusterAssment[i,:] = minIndex,minDist**2
        #print centroids
        for cent in range(k):         #对于每一个簇
            ptsInClust = dataSet[nonzero(clusterAssment[:,0].A==cent)[0]]#通过数组过滤得到簇中所有数据
                                                                         #.A 方法将matrix类型元素转化为array类型
                                                                         #在这里也可以不加
            centroids[cent,:] = mean(ptsInClust, axis=0) #将质心更新为簇中所有数据的均值
                                                         #axis=0表示沿矩阵的列方向计算均值
    return centroids, clusterAssment
