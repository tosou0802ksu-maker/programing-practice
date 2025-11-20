import sys                           # コマンドライン引数用
import time                          # 時間計測用
 
count = 0                            # 呼び出し回数をカウントするためのグローバル変数
def tarai(x, y, z):
    global count                     # 関数の外で定義された変数を関数内で使うために必要
    count = count + 1
    if x <= y:
        return y
    else:                            # 再帰呼び出し
        return tarai(tarai(x-1,y,z),tarai(y-1,z,x),tarai(z-1,x,y))

    

def call_tarai(x, y, z):
    global count                     # 関数の外で定義された変数を関数内で使うために必要
    count = 0                        # 呼び出し回数をリセット
    start = time.time()              # 実行開始時間を記録
    result = tarai(x, y, z)          # tarai 関数を実行
    end = time.time()                # 実行終了時間を記録
    print(f'tarai({x}, {y}, {z}) = {result} (呼び出し回数: {count}, 経過時間: {(end - start) * 1000}ms)')

if len(sys.argv) == 1:               # コマンドライン引数が指定されていない場合は、テスト用に3パターン実行
    call_tarai(10, 5, 0)
    call_tarai(10, 5, 1)
    call_tarai(12, 6, 0)
else:
    x = int(sys.argv[1])             # コマンドライン引数から x, y, z を取得して実行
    y = int(sys.argv[2])
    z = int(sys.argv[3])
    call_tarai(x, y, z)