points = [0, 8, 35, 14, 40, 20]
#０の時のことは考えないので一番最初の要素を最大最小点と考える前に消しておく
points.remove(0)
#最大最小を一番前にある要素として仮定して、points内の大小を比べる
p = 0
max = points[0]
min = points[0]
total = 0

#for文を使ってpoints内の要素の大小を全て比べる
#totalはそれぞれの要素を順に足していく
for p in points:
    if p > max:
        max = p
    if p < min:
        min = p
    total = total + p
average = total/len(points)

print("最高点は",max,"です。")
print("最低点は",min,"です。")
print("平均点は",average,"です。")
