import sys

def calc(value1, operator, value2):                            # 計算を行う関数                          
    if operator == "+":                                        # 四則演算の分岐処理
        result = value1 + value2
    elif operator == "-":
        result = value1 - value2
    elif operator == "*":
        result = value1 * value2
    elif operator == "/":
        if value2 ==0:                                         # ゼロ除算のチェック       
            print("Error")                                     # エラーメッセージを表示
            sys.exit(1)
        result = value1 / value2
    else:                                                      # 定義されていない演算子の場合       
        print("Error")
        sys.exit(1)                                            # 計算結果を返す
    return result                                                     
# --- 動作確認用テスト ---
                                                        
assert calc(3,"+",5) == 8 ,"Error: 加算が正しく動作しません。"      # 各演算が正しく動作するかを assert で確認する
assert calc(3,"-",5) == -2 ,"Error: 減算が正しく動作しません。"     # もし間違っていれば、指定したエラーメッセージを出して停止する
assert calc(3,"*",5) == 15,"Error: 乗算が正しく動作しません。" 
assert calc(15,"/",5) == 3,"Error: 除算が正しく動作しません。"
