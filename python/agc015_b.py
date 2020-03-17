s = list(raw_input())
ans = 0

l = len(s)
for i in range(l):
	if s[i] == 'U':
		ans += i*2 + (l-i-1)

	else :
		ans += i + (l-i-1)*2

print ans
