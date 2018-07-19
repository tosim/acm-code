# -*- coding: utf-8 -*-

import numpy as np
from sklearn.datasets import make_blobs


def distEclud(vecA, vecB):
    return np.sqrt(sum(np.power(vecA - vecB, 2)))

def kmediods(dataSet,k,distMethod=distEclud):
    n,m = dataSet.shape # 数据个数和属性个数
    kcenters = dataSet[np.random.choice(n,k,replace=False)] # k个初始化随机的中心点
    centerP = np.mat(np.zeros((n,2))) # 数据点的分配，第一列为所属簇，第二列为到此簇中心点的距离，第三列为倒数第二小的到中心点的距离
    chaneged = True
    while chaneged:
        chaneged = False
        # 将所有点分配到所属簇中去
        for i in range(n):
            minDist,minIndex = np.inf,-1
            # 找出所属簇
            for j in range(k):
                curDist = distMethod(dataSet[i,:],kcenters[j,:])
                if curDist < minDist:
                    minDist = curDist
                    minIndex = j
            if centerP[i,0] != minIndex:
                chaneged = True
                centerP[i,:] = minIndex,minDist

        #print("簇分配完毕")
        # 如果簇的分配没有变化
        if chaneged == False: break

        # 对于所有的中心点i,将绝对误差最小的点作为新的中心点
        for i in range(k):
            # 得到此簇的数据点
            ptsInCluster = dataSet[np.nonzero(centerP[:,0].A == i)[0],:]
            # 计算簇中各样本点的绝对误差最小的点，作为新的中心点
            minSum,minIndex = np.inf,-1
            # 计算所有点作为中心点的距离和
            for j in range(len(ptsInCluster)):
                jSum = 0
                for t in range(len(ptsInCluster)):
                    jSum += distMethod(ptsInCluster[t,:],ptsInCluster[j,:])
                if jSum < minSum:
                    minSum = jSum
                    minIndex = j
            if minIndex != -1:
                kcenters[i,:] = ptsInCluster[minIndex,:]

    return kcenters,centerP
