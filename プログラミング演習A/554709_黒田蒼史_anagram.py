data = list(map(int, input().split()))
num = len(data)
#奇数と偶数に分けて考える
if num % 2 == 0:
    #インデックスが半分ずつになるように分ける
    head = data[0:num//2]
    tail = data[num//2:num]
else:
    #中心の数を除くようにインデックスが半分になるように分ける
    head = data[0:num//2]
    tail = data[num//2+1:num]
#それぞれを比べるためにtailを反対向きにして比べる。
tail.reverse()
if head == tail:
    print("Anagram")
else:
    print("Not Anagram")
