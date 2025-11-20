#数を入力してもらう
sale=int(input("数を入力してください。"))
#1~入力した数待っでの合計を求める。
total = 0
for i in range(sale):
    total = total + (i+1)
    print(total)
print("合計は　",total)
