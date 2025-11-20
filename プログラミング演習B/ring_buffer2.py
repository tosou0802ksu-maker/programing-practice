class RingBuffer:
    def __init__(self, limit=None):
        self.limit = 12 if limit is None else limit
        self.list = [None] * self.limit
        self.count = 0  # add() を呼んだ回数（書き込み位置計算に使う）

    def get(self, place):
        # place が範囲外なら None
        if place < 0 or place >= self.count or place >= self.limit:
            return None

        # 最新の要素が index 0 になるように位置を計算
        pos = (self.count - 1 - place) % self.limit
        return self.list[pos]

    def add(self, number):
        # 次に書き込む位置
        pos = self.count % self.limit
        self.list[pos] = number
        self.count += 1

    def len(self):
        # 入っている数は limit を超えない
        return min(self.count, self.limit)


# ===== テストコード =====
rb1 = RingBuffer(3)
assert rb1.get(0) == None
rb1.add(1)
assert rb1.get(0) == 1
rb1.add(2)
rb1.add(3)
rb1.add(4)  # 1 が上書きされる
assert rb1.get(0) == 4
assert rb1.get(1) == 2
assert rb1.get(2) == 3
assert rb1.len() == 3

rb2 = RingBuffer()
assert rb2.get(0) == None
rb2.add("item1")
rb2.add("item2")
assert rb2.len() == 2
assert rb2.get(5) == None