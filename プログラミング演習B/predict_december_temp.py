import sys
from sklearn.linear_model import LinearRegression

def read_csv(filename):
    x, y = ([], [])
    with open(filename, "r") as f:
        f.readline()    # ヘッダ行を読み飛ばす．
        for line in f:
            year_str,temp_str = line.strip().split(",")
            year = int(year_str)
            temp = float(temp_str)
            x.append([year])
            y.append(temp)
    return x, y

x, y = read_csv(sys.argv[1]) # ファイル名はコマンドライン引数で指定する．

model = LinearRegression()# モデル（LinearRegression）のインスタンスを構築する．
model.fit(x,y)# 読み取ったデータを使ってモデルを学習する．

y_pred = model.predict([[2024]]) # x_test を 2024 にして，2024年12月の気温を予測する．

print(f"2024年12月の平均気温は {y_pred[0]} 度（予測）です．")