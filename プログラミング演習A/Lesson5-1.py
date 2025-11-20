points = [0, 8, 35, 14, 40, 20]
points.remove(0)
p = 0
max = points[0]
min = points[0]
total = 0


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
