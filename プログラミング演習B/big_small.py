import random

num = random.randint(1, 10) # 1 以上 10 以下の乱数を生成する
print(num)
if num >= 5:
    print ("Big") #5以上の時はBigと出力
else:
    print("Small")#5以下の時、それ以外の値の時Smallと出力
