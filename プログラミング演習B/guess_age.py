import sys

def find_age(age, low, high, step = 1):
    mid = (low + high) // 2

    if age == mid:
        return step                                   # 真ん中の値と年齢が一致したら終了
    elif age < mid:                                   
        return find_age(age,low,mid - 1,step + 1)     # 年齢が中間値より小さい場合、左側（lowからmid-1）を再帰的に探索
    else:
        return find_age(age,mid + 1,high,step + 1)    # 年齢が中間値より大きい場合、右側（mid+1からhigh）を再帰的に探索

for age_string in sys.argv[1:]:
    age = int(age_string)                             # 文字列を整数に変換
    step = find_age(age, 0, 100)                      # 0〜100歳の範囲で探索
    print(f'age = {age}, step = {step}')              # 結果を表示
