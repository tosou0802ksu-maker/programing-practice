f = open("Sample2.py", "r")
n = 0
while True:
    line = f.readline()
    if line == "":       
        break   
    n = n+1
    print("{:3d}: {}".format(n, line), end="")

f.close()