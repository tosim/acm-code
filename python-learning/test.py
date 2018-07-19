import numpy as np

a = np.mat(np.zeros((10,2)))
b = np.mat(np.ones((10,2)))

a[1,:] = b[1,:]
print(a)
print(b)
