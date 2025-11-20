point = [8,10,35,14,40,20]
i = 0
max = point[0]
while i <= 5:
    if max<point[i]:
        max = point[i]
    i = i +1

print(max)