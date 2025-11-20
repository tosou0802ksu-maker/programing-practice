import sys

                                                                          # 年ごとの気象データを格納する辞書を初期化
                                                                          # 形式：{ 年: (猛暑日数, 真夏日数, 夏日数, 真冬日数, 冬日数, 日数) }

dic = {}
years = set()

with open(sys.argv[1],"r") as f:
    f.readline()                                                          #１行目を読み飛ばす
    for line in f.readlines():                                            # 2行目以降を1行ずつ処理する
        (date, max_s, min_s, rests) = line.split(",")                     # 行をコンマで分割し，それぞれを代入する．
        (year, max, min) = (date[:4], float(max_s), float(min_s))         
        (extremely_hot, hot, summer, ice, frost) = (0, 0, 0, 0, 0)

        if max >= 35:                                                     # 最高気温が35℃以上 → 猛暑日
            extremely_hot = 1
        elif max >= 30:                                                   # 最高気温が30℃以上 → 真夏日
            hot = 1 
        elif max >= 25:                                                   # 最高気温が25℃以上 → 夏日
            summer = 1
        if max < 0:                                                       # 最高気温が0℃未満 → 真冬日
            ice = 1
        if min < 0:                                                       # 最低気温が0℃未満 → 冬日
            frost = 1

        years.add(year)                                                   # 年を集合に追加する

        if year in dic:                                                   # dic[year] からタプルとして，猛暑日，真夏日，夏日，真冬日，冬日，日数を取り出す．
            (e,h,s,i,fr,days) = dic[year]                                 # その際，判定とところで得られた extermely_hot, hot, summer, ice, frost をそれぞれに加算する

            dic[year] = (e + extremely_hot,h + hot,s + summer,i + ice,fr + frost,days + 1)
                                                                          # それぞれの項目に当日の値を加算、日数も+1
        else:
            dic[year] = (extremely_hot, hot, summer, ice, frost, 1)

for year in sorted(years):                                                # 年を昇順にソートして繰り返す．
    (extremely_hot, hot, summer, ice, frost, days) = dic[year]
    print(f"{year}  猛暑日 {extremely_hot:>3}, 真夏日 {hot:>2}, 夏日 {summer:>2}, 真冬日 {ice:>2}, 冬日 {frost:>2} ({days:>3}日)")
