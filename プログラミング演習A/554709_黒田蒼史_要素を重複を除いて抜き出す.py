data = list(map(int, input().split()))
unique = [ ]
print("data =", data)
#data内にある数値を一つずつチェックする
for n in data:
    #uniqueにその数値がないときはunique加えた上げることで、数値があるときは加わることがないため数字の重なりがなくなる
    if n not in unique:
        unique.append(n)
    print(n) #nがdata内の数字が認識されているかの確認用
print("unique =", unique)
