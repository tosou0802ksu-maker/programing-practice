year=int(input("年を入力してください。"))

if (year%4==0) and ((year%100!=0) or (year%400 == 0)):
    print("YES")
else:
    print("NO")

print("処理を終了します。")