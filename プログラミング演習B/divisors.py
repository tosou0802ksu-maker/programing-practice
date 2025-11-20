import sys   # コマンドライン引数を取得するためのライブラリ

for value in sys.argv[1:]:      # コマンドライン引数を順に処理する．
    num = int(value)            # コマンドライン引数を整数に変換する．
    divisors = []               # 約数を格納するリストを初期化する．
    
    for i in range(1,num+1):
        if num % i ==0:
            divisors.append(i)
    # 1からnum（を含む）範囲で繰り返す
        # num が i で割り切れるとき divisors に i を追加する．
    print(f"{num}: {divisors}") #15 num（数値）と divisors（約数一覧）を出力する．
    