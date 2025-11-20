import sys

def count_chars(str):                       # 関数 count_chars: 与えられた文字列中の各文字の出現頻度を数える
    
    freq = dict()                           # 文字とその出現回数を記録する辞書を作成
    for c in str.lower():
        if c not in freq:                   # もし文字 c が辞書にまだ登録されていなければ、カウントを0に初期化
            freq[c] = 0

        freq[c] +=1                         # 文字 c の出現回数を1増やす

    return freq                             # 出現頻度をまとめた辞書を返す

for arg in sys.argv[1:]:                    # コマンドライン引数として与えられた文字列を順に処理
    print(f"{arg}: {count_chars(arg)}")