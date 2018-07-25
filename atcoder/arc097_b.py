class UnionFind():
    def __init__(self,size):
        self.table = [-1 for _  in range(size)]

    def find(self,x):
        while self.table[x] >= 0:
            x = self.table[x]
        return x

    def union(self,x,y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.table[s1] != self.table[s2]:
                if self.table[s1] < self.table[s2]:
                    self.table[s2] = s1
                else:
                    self.table[s1] = s2
            else:
                self.table[s1] += -1
                self.table[s2] = s1
        return

n,m = map(int,raw_input().split())

arr = map(int,raw_input().split())

uf = UnionFind(n)

for i in range(m):
    f,t = map(int,raw_input().split())
    f -= 1
    t -= 1
    uf.union(f,t)

ans = 0
for i in range(n):
    if uf.find(i) == uf.find(arr[i]-1):
        ans += 1

print ans


