#1~10の文字数の確認なので、countが0のものを10こ作っておく
count = [0]*10
#テキストをinuputする
Alice = input()
n=1
#ファイルを読み込みモードでオープンにする
f = open(Alice,"r")
#全ての行の読み出し
lines = f.readlines()
f.close()
#読み出した行を文字列として１行ずつ取り出す
for line in lines:
    line = line.split()
    print(line)#確認用
#さらに文字列を単語ごとのリストに分けていく
    for word in line:
        print(word)#確認用
#単語の文字数を数える
        length = len(word)
#文字数が0のリストは無視する
        if length ==0:
            continue
#文字数が10以上のものは一つにして数える
        elif length >= 10:
            count[9] += 1
#その他の数字はcountと文字数を関係づけて数える
        else:
            count[length-1] +=1
print("len","count","|")
#文字数が1~10までの結果を縦向きに並べるためにfor文を使う
for s in range(n,11):
#format()で中央揃えを使って結果の出力を見やすくする。
    print("{:^3} {:^5} | {}".format(s, count[s-1], "*" * count[s-1]))
