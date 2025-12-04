class Vector:
    def __init__(self, *n):
        # 可変長引数で受け取った値をリストとして保持
        self._elements = list(n)

    def __add__(self, other):
        # 要素数が同じ場合のみベクトルの足し算をする
        if len(self) == len(other):
            # zip で対応する要素同士を加算し、新しい Vector を返す
            return Vector(*[a + b for a, b in zip(self._elements, other._elements)])
        return None  # 要素数が異なる場合は None

    def __mul__(self, other):
        # 要素数が同じ場合のみ内積を計算する
        if len(self) == len(other):
            # 対応する要素同士を掛けて合計
            return sum(a * b for a, b in zip(self._elements, other._elements))
        return None  # 要素数が異なる場合は None

    def __getitem__(self, index):
        # インデックス指定で要素を取得できるようにする
        return self._elements[index]

    def __len__(self):
        # ベクトルの長さ（要素数）を返す
        return len(self._elements)

    def __str__(self):
        # ベクトルを "(1, 2, 3)" の形式で表示
        return f"({', '.join(str(x) for x in self._elements)})"

    def norm(self):
        # ベクトルのノルム（長さ）を計算：√(x1^2 + x2^2 + ... )
        return sum(x ** 2 for x in self._elements) ** 0.5
    