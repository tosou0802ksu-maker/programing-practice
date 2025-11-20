#554709 黒田蒼史

#数を入力してもらう
number= int (input("数を入力してください。"))
count = 0 
for i in range(1,number+1): #1~入力した数で割り、割り切れるになる回数を調べる
    print("check",i,end="")
    if number % i ==0:#割り切れた場合の数を数えておく。
        count=count+1
    print()#改行を追加
if count == 2:#割り切れる回数がちょうど2回の時は素数。
    print("素数である。")#そうではない時は素数ではない。
else:print("素数ではない。")
