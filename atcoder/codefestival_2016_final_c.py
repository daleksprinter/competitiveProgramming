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
#-----------------------------------------------------
n,m = map(int,raw_input().split())

uf = UnionFind(n+m)

for i in xrange(n):
	langs = map(int,raw_input().split())
	for j in xrange(1,langs[0] + 1):

		uf.union(i,langs[j]+n-1)

a = uf.find(0)

for i in range(1,n):
	root = uf.find(i)

	if uf.find(i) != a:
		print 'NO'
		quit()

print 'YES'
