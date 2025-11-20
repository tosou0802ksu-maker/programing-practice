import sys

def combination(n, k):

    if n < k:                                                # k が n より大きい場合は組み合わせは存在しないので 0 を返す
        return 0
    elif k == 0 or n == k:                                   # k が 0 または k == n の場合は組み合わせは 1 通り
        return 1
    else:
        return combination(n-1,k) + combination(n-1,k-1)     # 再帰呼び出し：C(n, k) = C(n-1, k-1) + C(n-1, k)
    
n = int(sys.argv[1])                                         # コマンドライン引数から n と k を取得
k = int(sys.argv[2])
print(f'combination({n}, {k}) = {combination(n, k)}')        # 結果を表示
