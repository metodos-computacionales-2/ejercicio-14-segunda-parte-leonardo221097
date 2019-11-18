import numpy as np
import matplotlib.pylab as plt


data1=np.loadtxt('datos-array.txt')
x=data1[:,0]
y=data1[:,1]
v= data1[:,2]
plt.figure(1)
plt.plot(x,y)
plt.savefig('rk4.png')

plt.figure(2)
plt.plot(y,v)
plt.savefig('yvsvelrk4.png')

data=np.loadtxt('datos-arrayfriccion.txt')
x1=data[:,0]
y1=data[:,1]
v1= data[:,2]
plt.figure(3)
plt.plot(x1,y1)
plt.savefig('rk4friccion.png')

plt.figure(4)
plt.plot(y1,v1)
plt.savefig('yvsvelrk4friccion.png')

