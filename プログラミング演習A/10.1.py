f = open("message.txt","w")

f.write("こんにちは\n")
f.write("さようなら\n")

f.close()

f = open("message.txt","r")
lines = f.readlines()
for line in lines:
    print(line,end="")
f.close()

f = open("message.txt","w")

f.write("こんにちは")
f.write("さようなら")

f.close()

f = open("message.txt", "r")
lines = f.readlines()
print(lines)