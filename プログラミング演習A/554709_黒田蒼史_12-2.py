import random
import matplotlib.pylab as plt

x = []
y = []
#x,yの0~50の範囲にランダムに100個のマークをする
for i in range(100):
    x.append(random.uniform(0,50))
    y.append(random.uniform(0,50))
#x,yの範囲をそれぞれ-100~100に設定する
plt.xlim(-100,100)
plt.ylim(-100,100)
#散布図を作成し、マークをxにする
plt.scatter(x,y,marker = "x",)
#グラフを表示させる
plt.show()