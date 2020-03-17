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

edges = [map(int,raw_input().split()) for i in range(m)]

ans = 0

for i in range(m):
	uf = UnionFind(n)
	for j in range(m):
		if i != j:
			uf.union(edges[j][0]-1,edges[j][1]-1)

	c = 0
	for j in range(n):
		if j == uf.find(j):
			c += 1

	if c > 1 :
		ans += 1

print ans

