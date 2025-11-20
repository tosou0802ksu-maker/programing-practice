import sys
import os

                                                        # name という名前のファイルを base 以下から探す関数．
                                                        # 複数見つかる場合もありうるため，見つかったものをリストで返す．
def find_file(name, base, result = None):
    if result is None:
        result = []
                                                        # base がディレクトリの場合
    if os.path.isdir(base):
        for item in os.listdir(base):
                                                        # base の一覧を取得し，それぞれを処理する．
            path=os.path.join(base,item)                # それぞれのアイテムに対して，base と item を join する．
                                                        # find_file を再起的に呼び出す．
            find_file(name,path,result)
                                                        # そうでない場合
    else:
        filename = os.path.basename(base)               # base から ファイル名部分を取り出す．
                                                        # filename が name と一致する場合
        if filename == name:  
            result.append(base)
                                                        # result に base を追加する．
    return result

for base in sys.argv[2:]:                               # コマンドライン引数処理
    paths = find_file(sys.argv[1], base)
    if paths:
        print(f"{sys.argv[1]}: {paths}")