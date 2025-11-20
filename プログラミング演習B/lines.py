import sys

for filename in sys.argv[1:]:       
    with open(filename, "r") as f:   #ファイルを開けて読み込みモードで指定したファイルを読み込む
        a = len(f.readlines())       #行数を数える
        print(a,filename)
