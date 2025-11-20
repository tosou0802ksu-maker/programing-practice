import random
import matplotlib.pyplot as plt

data = []
#1000このデータをランダムに表示する
#このとき平均値0,標準偏差10のグラフにしたいのでそう設定する
for i in range (1000):
    data.append(random.normalvariate(0,10))
#タイトルをつける
plt.title("Histogram")
#dataを入れ、階級数を50に設定する
plt.hist(data,bins=50)
plt.show()