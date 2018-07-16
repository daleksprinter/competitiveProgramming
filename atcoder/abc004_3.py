n = int(input())

s = "123456"

t = list(s[(n/5)%6:] + s[:(n/5)%6])

for i in range(n%5):
	t[i],t[i+1] = t[i+1],t[i]

print ''.join(t)
