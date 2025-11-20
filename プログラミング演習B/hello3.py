def hello(a = None):              # hello 関数の定義
    if a is None:                 # 引数 a が与えられなかった時（デフォルト値 None のとき）
        return "Hello World"      
    elif a == "World":            # 引数が "World" の場合は、特別に "Hi! World" を返す
        return "Hi! World"
    else:                         # それ以外の文字列が与えられた場合は、"Hello " + その文字列 を返す
        return "Hello " + a
                                  # ====== 以下はテストコード（assert文） ======
                                  
assert hello() == "Hello World",          "Error: hello() が 'Hello World' を返しません．"
assert hello("Python") == "Hello Python", "Error: hello('Python') が 'Hello Python' を返しません．"
assert hello("World") == "Hi! World",     "Error: hello('World') が 'Hi! World' を返しません．"
