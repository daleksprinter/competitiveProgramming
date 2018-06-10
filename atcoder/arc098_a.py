n = int(input())

s = list(raw_input())

cs = []
for i in range(n):
	if s[i] == 'E':
		s[i] = 1
	else :
		s[i] = 0

cs.append(s[0])

for i in range(1,n):
	cs.append(cs[i-1]+s[i])

ans = cs[n-1]-cs[0]
for i in range(1,n):
	ans = min( cs[n-1]-cs[i] + i-cs[i-1],ans)

print ans
