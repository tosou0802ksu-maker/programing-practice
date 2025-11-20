import sys                                                            # コマンドライン引数を扱うためのモジュールをインポート

def calc(value1, operator, value2):                                   # 計算を行う関数
    if operator == "+":
        result = value1 + value2
    elif operator == "-":
        result = value1 - value2
    elif operator == "*":
        result = value1 * value2
    elif operator == "/":
        if value2 ==0:                                                # 0で割ろうとした場合はエラー表示して終了
            print("Error")
            sys.exit(1)
        result = value1 / value2
    else:                                                             # 対応していない演算子の場合はエラー表示して終了
        print("Error")
        sys.exit(1)
    return result                                                     # 計算結果を返す

if len(sys.argv) != 4:                                                # コマンドライン引数の個数をチェック
    print('Usage: python3 calc.py <value1> <operator> <value2>')      # 引数が3つでない場合、使い方を表示して終了
    sys.exit(1)                                                       # 引数を取得して整数や文字列に変換
value1 = int(sys.argv[1])                                             # 1つ目の値を整数に変換
operator = sys.argv[2]                                                # 演算子を文字列として取得
value2 = int(sys.argv[3])                                             # 2つ目の値を整数に変換
print(calc(value1, operator, value2))                                 # 計算して結果を出力
