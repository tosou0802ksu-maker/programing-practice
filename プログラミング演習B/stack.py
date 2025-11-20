class Stack:
    def __init__(self, items=None):
        # 初期化：items が渡されなければ空リストを作る
        if items is None:
            self.items = []
        else:
            self.items = list(items)  # 渡されたリストをコピーして保持

    def push(self, item):
        # スタックの一番上に item を追加
        self.items.append(item)

    def pop(self):
        # スタックの一番上の要素を取り出す
        # スタックが空なら None を返す
        if len(self.items) == 0:
            return None
        return self.items.pop()
        
    def peek(self):
        # スタックの一番上の要素を返すが削除はしない
        if len(self.items) == 0:
            return None
        return self.items[-1]

    def len(self):
        # スタックにある要素数を返す
        return len(self.items)
        
s1 = Stack()
s1.push("This")
s1.push("is")
s1.push("stack")
s1.push("test")

assert s1.len() == 4, "スタックの長さは4になっているはずです"
assert s1.peek() == "test", "peek() は最後の要素である test を返すべきです"
assert s1.len() == 4, "peek() は要素の長さを変更しません"

assert s1.pop() == "test",  "pop() は最後の要素である test を返すべきです"
assert s1.pop() == "stack", "pop() は最後の要素である stack を返すべきです"
assert s1.pop() == "is",    "pop() は最後の要素である is を返すべきです"
assert s1.pop() == "This",  "pop() は最後の要素である This を返すべきです"
assert s1.len() == 0, "スタックの長さは0になっているはずです"

s2 = Stack([1, 2, 3, 4, 5]) # コンストラクタで要素を指定できる．
assert s2.len() == 5, "スタックの長さは5になっているはずです"
s2.pop()
s2.pop()
s2.pop()
s2.pop()
s2.pop()
assert s2.len() == 0, "スタックの長さは0になっているはずです"

s3 = Stack()
assert s3.pop() == None, "空のスタックから pop() すると None が返るべきです"