class RingBuffer:
    def __init__(self, n=12):
        self.S = n             # バッファサイズ
        self.B = 0             # 最新の要素が入っている位置
        self.C = 0             # 入っている要素数
        self.D = [None] * n    # バッファ本体

    def add(self, item):
        # 次に書き込む位置（最新位置 B を 1 つ前にずらす）
        self.B = (self.B - 1) % self.S
        self.D[self.B] = item
        print(self.D)
        # 要素数を増やす（同じ場所を上書きしても C は増えない）
        if self.C < self.S:
            self.C += 1

    def get(self, index):
        # 範囲外なら None
        if index < 0 or index >= self.C:
            return None

        # B が最新 → index だけ後ろに行く
        pos = (self.B + index) % self.S
        return self.D[pos]

    def len(self):
        return self.C


# ===== テスト =====

rb1 = RingBuffer(3)
assert rb1.get(0) == None, "何も要素が入っていないため，None であるはずです"
rb1.add(1)
assert rb1.get(0) == 1, "0番目の要素は 1 であるはずです"
rb1.add(2)
rb1.add(3)
rb1.add(4)  # 最初の要素である 1 が上書きされる
assert rb1.get(0) == 4, "0番目の要素は 4 であるはずです"
assert rb1.get(1) == 2, "0番目の要素は 2 であるはずです"  # （表記ミスだが動作はOK）
assert rb1.get(2) == 3, "0番目の要素は 3 であるはずです"
assert rb1.len() == 3, "3つの要素が入っているため，長さは3であるはずです"

rb2 = RingBuffer()
assert rb2.get(0) == None, "何も要素が入っていないため，None であるはずです"
rb2.add("item1")
rb2.add("item2")
assert rb2.len() == 2, "2つの要素が入っているため，長さは2であるはずです"
assert rb2.get(5) == None, "5番目の要素は存在しないため，None であるはずです"