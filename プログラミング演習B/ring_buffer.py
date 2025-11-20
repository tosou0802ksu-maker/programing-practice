class RingBuffer:
    def __init__(self,limit = None):
        self.S = []
        self.P = 0                                   # 追加された回数
        if limit == None:
            self.limit = 12                          # バッファサイズ
        else:
            self.limit = limit
            
    def get(self,place):
        if len(self.S) <= 0 or len(self.S) < place:  # バッファが空、または取ろうとしている位置が長さ以上なら None
            return None
        else:
            return self.S[place]                     # 指定位置の要素を返す
            
    def add (self,number):                           # number が str または number <= limit の場合は append
        if type(number) == str or number <= self.limit:
            self.S.append(number)
        else:
            place = self.P % self.limit              # バッファサイズを超える場合の上書き位置
            self.S[place] = number
        self.P += 1                                  # 追加回数をカウント
    
    def len(self):
        return len(self.S)                           # 現在のバッファの要素数を返す
    

# ===== テストコード =====
rb1 = RingBuffer(3)
assert rb1.get(0) == None, "何も要素が入っていないため，None であるはずです"
rb1.add(1)
assert rb1.get(0) == 1, "0番目の要素は 1 であるはずです"
rb1.add(2)
rb1.add(3)
rb1.add(4)  # 最初の要素である 1 が上書きされる
assert rb1.get(0) == 4, "0番目の要素は 4 であるはずです"
assert rb1.get(1) == 2, "0番目の要素は 2 であるはずです"
assert rb1.get(2) == 3, "0番目の要素は 3 であるはずです"
assert rb1.len() == 3, "3つの要素が入っているため，長さは3であるはずです"

rb2 = RingBuffer()
assert rb2.get(0) == None, "何も要素が入っていないため，None であるはずです"
rb2.add("item1")
rb2.add("item2")
assert rb2.len() == 2, "2つの要素が入っているため，長さは2であるはずです"
assert rb2.get(5) == None, "5番目の要素は存在しないため，None であるはずです"