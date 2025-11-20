year1=int(input("自分のじゃんけんに対応した数字を入力してください。"))
year2=int(input("相手のじゃんけんに対応した数字を入力してくだいさい。"))
#1,グー　2,チョキ　3,パー
if year1 == year2:
    print("even") 
elif year1 - year2 ==1:
    print ("lose")
elif year1 - year2 ==-2:
    print("lose")
else:print("win")

print("処理を終了します。")
