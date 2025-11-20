def hello(name=None):                # 関数 hello の定義
    if name is None:                 # 引数がない場合
        return "Hello World"
    
    elif name == "Python":           # 引数がない場合
        return "Hi! Python"
    else:                            # その他の文字列が与えられた場合
        return "Hello " + name

assert hello() == "Hello World",          "Error: hello() が 'Hello World' を返しません．"
assert hello("Python") == "Hi! Python",   "Error: hello('Python') が 'Hi Python' を返しません．"
assert hello("Tamada") == "Hello Tamada", "Error: hello('Tamada') が 'Hello Tamada' を返しません．"
