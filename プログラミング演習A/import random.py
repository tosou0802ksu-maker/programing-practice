import random
import matplotlib.pylab as plt

x = []
y = []

for i in range(100):
    x.append(random.uniform(0,50))
    y.append(random.uniform(0,50))
plt.xlim(-100,100)
plt.ylim(-100,100)
plt.scatter(x,y,marker = "x",)
plt.show()