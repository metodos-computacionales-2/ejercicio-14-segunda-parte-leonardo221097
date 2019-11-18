import numpy as np
import matplotlib.pylab as plt


data=np.loadtxt('euler.dat')
x1= data[:,0]
y1= data[:,1]
v=  data[:,2]
plt.figure(1)
plt.plot(x1,y1)
plt.savefig('euler.png')

plt.figure(2)
plt.plot(v,y1)
plt.savefig('yvsveleuler.png')




