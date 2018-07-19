# -*- coding:utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import random

#from sklearn.cluster import KMeans
from sklearn.datasets import make_blobs
from my_kmeans import kMeans
from my_kmediods import kmediods

def mkdata():
    data = []
    y = []
    #这里300个点
    for i in range(10):
        for j in range(10):
            data.append([i,j])
            data.append([i,100+j])
            data.append([100+i,j])
            y.append(0)
            y.append(1)
            y.append(2)
    for i in range(70):
        data.append([10+random.randint(1,89),10+random.randint(1,89)])
        y.append(random.randint(0,2))

    data = np.array(data)
    y = np.array(y)
    return data,y

plt.figure(figsize=(15, 12))

# 选取样本数量
n_samples = 1500
# 选取随机因子
random_state = 170
# 簇的个数
centers = 3
# 数据的维度
n_features = 2
# 获取数据集
#X, y = make_blobs(n_samples=n_samples, random_state=random_state,centers=centers,n_features=n_features)
X,y = mkdata()

plt.subplot(131)
plt.scatter(X[y==0][:, 0], X[y==0][:, 1], marker='x',color='b')
plt.scatter(X[y==1][:, 0], X[y==1][:, 1], marker='+',color='r')
plt.scatter(X[y==2][:, 0], X[y==2][:, 1], marker='o',color='g')
# plt.scatter(X[a==3][:, 0], X[a==3][:, 1], marker='v',color='y')
plt.title("correct")


#y_pred = KMeans(n_clusters=3, random_state=random_state).fit_predict(X)
# k-means
centroids,clusterAssment = kMeans(X,centers)
a = (clusterAssment[:,0].T.A)[0]

#pam
kcenter,centerP = kmediods(X,centers)
c = (centerP[:,0].T.A)[0]
#print(c)

plt.subplot(132)
plt.scatter(X[a==0][:, 0], X[a==0][:, 1], marker='x',color='b')
plt.scatter(X[a==1][:, 0], X[a==1][:, 1], marker='+',color='r')
plt.scatter(X[a==2][:, 0], X[a==2][:, 1], marker='o',color='g')
# plt.scatter(X[a==3][:, 0], X[a==3][:, 1], marker='v',color='y')
plt.title("kmeans")


plt.subplot(133)
plt.scatter(X[c==0][:, 0], X[c==0][:, 1], marker='x',color='b')
plt.scatter(X[c==1][:, 0], X[c==1][:, 1], marker='+',color='r')
plt.scatter(X[c==2][:, 0], X[c==2][:, 1], marker='o',color='g')
# plt.scatter(X[c==3][:, 0], X[c==3][:, 1], marker='v',color='y')
plt.title("kmidos-pam")
plt.show()



