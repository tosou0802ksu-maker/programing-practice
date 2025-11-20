import sys                                      # n >= 2 と定義する

def fibonacci(n):                               # 最初の2つの項（1, 1）の場合は 1 を返す
    if n == 1 or n == 2:
        return 1
    elif n > 2:
        return fibonacci(n-1)+fibonacci(n-2)    # それ以外の場合は、再帰的に前の2項の和を計算する

for arg in sys.argv[1:]:
    n = int(arg)                                # 引数を整数に変換
    print(f'fibonacci({n}) = {fibonacci(n)}')   # 結果を表示