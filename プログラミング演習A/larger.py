sale1=int(input("num1を入力してください。"))
sale2=int(input("num2を入力してください。"))
sale3=int(input("num3を入力してください。"))

answer=sale1
if answer<sale2:
    answer=sale2
if answer<sale3:
    answer=sale3

print(answer)    

