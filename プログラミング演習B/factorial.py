import sys                                    # コマンドライン引数を扱うためのモジュールをインポート

def factorial(n):                             # 階乗を計算する関数
    if n < 0:                                 # 負の数の階乗は定義されていないため、何もしない
        pass
    elif  n == 0 or n == 1:                   # 0! と 1! は 1 と定義されている
        return 1
    else:                                     # n! を計算するための変数 a を 1 で初期化
        a = 1
        for s in range(1,n+1):                # 1 から n までの整数を順番に掛け合わせる
            a *= s
        return a
for arg in sys.argv[1:]:                      # コマンドライン引数で渡された各数値に対して階乗を計算して出力
    n = int(arg) 
    print(f"{n}! = {factorial(n)}")
