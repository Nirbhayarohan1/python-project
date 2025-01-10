import numpy as np
n1=np.array([1,2,3,4])
n2=np.array([[1,2,3,4],[5,6,7,8]])
n3=np.full((99,99),5)
n4=np.arange(1,9)
n5=np.arange(10,20,5)
n7=np.random.randint(1,100,5)
n1=[10,20]
n2=[30,40]
np.sum([n1,n2])
np.sum([n1,n2],axis=0)
np.sum([n1,n2],axis=1)
np.save("abc",n2)
n10=np.load("abc.npy")
print(n10)