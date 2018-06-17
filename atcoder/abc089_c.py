import itertools
n = int(raw_input())

d = {'M':0,'A':0,'R':0,'C':0,'H':0}

for i in range(n):
	s = raw_input()
	if d.has_key(s[0]):
		d[s[0]] += 1

count = 0

for comb in list(itertools.combinations(d.keys(),3)):
	count += d[comb[0]]* d[comb[1]]*d[comb[2]]

print count
