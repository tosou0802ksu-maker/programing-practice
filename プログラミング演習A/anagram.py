data = list(map(int, input().split()))
num = len(data)
if num % 2 == 0:
    head = data[0:num//2]
    tail = data[num//2:num]
else:
    head = data[0:num//2]
    tail = data[num//2+1:num]

tail.reverse()
if head == tail:
    print("Anagram")
else:
    print("Not Anagram")
