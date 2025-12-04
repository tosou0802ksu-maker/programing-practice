class MyRandom:
    
    def __init__(self, seed=0, modulus=2**32, multiplier=1664525, increment=1013904223):
        self._seed = seed
        self._modulus = modulus
        self._multiplier = multiplier
        self._increment = increment
        
    def next(self, count = 0): # count が指定された場合，count 回乱数を生成します．
        result = self._next_impl()
        if count > 0:
            return self.next(count - 1)
        return result

    def _next_impl(self):

    # 次の状態を計算
        self._seed = (self._multiplier * self._seed + self._increment) % self._modulus
        
        return self._seed / self._modulus
    