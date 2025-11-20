import sys

def collatz(x, list):                                        # Collatz関数（再帰を用いて数列を生成）
    list.append(x)                                           # 現在の値をリストに追加
    if x != 1:                                               # 1でなければ次の処理へ
       if x % 2 == 0:                                        # xが偶数の場合
           return collatz(x//2,list)                         # xを2で割った値を次のステップに
       else:                                                 # xが奇数の場合
           return collatz(3*x+1,list)                        # 3x+1を次のステップに
    return list                                              # xが1になったらリストを返す

for value in sys.argv[1:]:
    n = int(value)                                           # 文字列を整数に変換
    list = []
    collatz(n, list)                                         # 関数を呼び出してリストを埋める
    print(f'collatz({n}) = {list} ({len(list)} steps)')