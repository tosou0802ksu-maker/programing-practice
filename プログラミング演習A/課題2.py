average = 0 #平均
total =  0#合計
count = 0#何回か数を入力したか
#一つ目の数の入力をしてもらう
num=float(input("数を入力してください。"))
#要素数を数える機能を追加し、平均を求めるプログラムを書く
while num > 0:
    count = count+1#何回入力したか
    total = num + total#合計
    average = total/count#平均
#２つ目の数を入力してもらう
    num = int(input("数を入力してください。"))
print("平均は　",average)
print(count,total) #確認用
