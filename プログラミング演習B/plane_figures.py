import math

# ----------------------
# 2次元平面上の点を表すクラス
# ----------------------
class Point:
    def __init__(self, x, y):
        self._x = x
        self._y = y

    # abs(point) で原点からの距離を返す
    def __abs__(self):
        return math.hypot(self._x, self._y)

    # 他の点との距離を計算、other が None なら原点から
    def distance(self, other=None):
        if other is None:
            length = self  # 自分自身から原点まで
        else:
            length = self - other  # 他の点との差ベクトル
        return abs(length)

    # 点の差を計算して新しい Point を返す
    def __sub__(self, other):
        return Point(self._x - other._x, self._y - other._y)

    # 文字列表示 "(x, y)"
    def __str__(self):
        return f"({self._x}, {self._y})"


# ----------------------
# 線分を表すクラス
# ----------------------
class Line:
    def __init__(self, L1, L2):
        self._L1 = L1  # 線分の始点
        self._L2 = L2  # 線分の終点

    # 線分の長さを返す
    def distance(self):
        return self._L1.distance(self._L2)

    # 文字列表示 "((x1, y1), (x2, y2))"
    def __str__(self):
        # 修正: タプル表記ではなく、Point.__str__ を呼ぶ
        return f"({self._L1}, {self._L2})"

    # 点が線分上にあるか判定
    def is_on(self, L):
        # 修正: 属性は _x, _y
        x1, y1 = self._L1._x, self._L1._y
        x2, y2 = self._L2._x, self._L2._y
        x, y = L._x, L._y

        # 垂直線の判定
        if abs(x2 - x1) < 1e-8:
            if abs(x - x1) > 1e-5:
                return False
        else:
            # 修正: 傾き a の計算
            a = (y2 - y1) / (x2 - x1)
            y_expected = y1 + a * (x - x1)
            if abs(y_expected - y) > 1e-5:
                return False

        # 線分の範囲内にあるか
        return (min(x1, x2) - 1e-5 <= x <= max(x1, x2) + 1e-5 and
                min(y1, y2) - 1e-5 <= y <= max(y1, y2) + 1e-5)