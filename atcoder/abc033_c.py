s = raw_input()
l = len(s)

stk = []
ans = 0
for i in range(l):
	if s[i] == '*':
		next
	elif s[i] == '+':
		if 0 in stk:
			del stk[:]
		else :
			ans += 1
			del stk[:]

	else:
		stk.append(int(s[i]))

if not 0 in stk:
	ans += 1

print ans
