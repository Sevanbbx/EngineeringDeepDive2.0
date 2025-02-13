from random import randint

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = []

    def fill_randomly(self):
        self.tree.append([randint(1, 100) for _ in range(self.n)])
        self.__build(self.n)
    
    def __build(self, n, level_num=0):
        if not n:
            n = self.n
        while n > 1:
            level = []
            for i in range(0, n - 1, 2):
                level.append(max(self.tree[level_num][i], self.tree[level_num][i + 1]))
            if n % 2 == 1:
                level.append(self.tree[level_num][-1])
            self.tree.append(level)
            n = (n // 2) + (n % 2)
            level_num += 1
    
    def get_max_in_range(self, begin, end):
        max_val = float('-inf')
        level = 0
        while begin < end:
            if begin % 2 == 1:
                max_val = max(max_val, self.tree[level][begin])
                begin += 1
            if end % 2 == 0:
                max_val = max(max_val, self.tree[level][end])
                if end > 2:
                    end -= 1
            begin //= 2
            end //= 2
            level += 1
        return max_val


    def print(self):
        spaces = 2
        for level in range(len(self.tree)):
            print((spaces+1) * ' ', end='')
            for val in range(len(self.tree[level])):
                print(str(self.tree[level][val]), end=spaces * '  ')
            print()
            spaces *= 2


fenwick_tree = FenwickTree(7)
fenwick_tree.fill_randomly()
fenwick_tree.print()
print(f"{fenwick_tree.get_max_in_range(0, 2)}")

        
        


