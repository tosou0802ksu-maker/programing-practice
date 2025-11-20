import random                     # 乱数を生成するためのライブラリ

randoms = []

max = 1                           # 最大値
min = 1000                        # 最小値
sum = 0                           # 合計値の初期値を適切に設定しましょう．
num = 0

for i in range(100):              # 0〜99 まで繰り返す（100は含まない）．
    randoms.append(num)
    num = random.randint(1, 1000) #1~1000までのランダムの数字を入れていく
    sum = sum + num
    if max <= num:                #最大値を書き換えていく      
        max = num                 #最小値を書き換えていく
    if min >= num:
        min = num

average = sum/100

print("max:",max,",""min:",min,",""sum:",sum,",""avg:",average,)
for a,b in enumerate(randoms):
    if a%10 == 9:                 #10この数字ごとに改行したいので、10で割った時の余りが9の時改行
        print()
print(f"{a:>4}".format(b))        #右寄せに4桁で表示
