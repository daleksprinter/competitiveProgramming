n, k, l = map(int,raw_input().split())

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

uf_road = UnionFind(n)
uf_rail = UnionFind(n)

for i in range(k):
	f,t = map(int,raw_input().split()); f -= 1; t -= 1
	uf_road.union(f, t)

for i in range(l):
	f,t = map(int,raw_input().split()); f -= 1; t -= 1
	uf_rail.union(f, t)
road = [0]*n
rail = [0]*n
for i in range(n):
	road[i] = uf_road.find(i)
	rail[i] = uf_rail.find(i)

ans = {}

for i in range(n):
	key = (road[i],rail[i])
	count = ans.get(key)
	ans[key] = 1 if not count else count + 1

ret = []
for i in range(n):
	key = (road[i],rail[i])
	ret.append(str(ans.get(key)))

print ' '.join(ret)





