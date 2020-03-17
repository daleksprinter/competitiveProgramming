s = raw_input()

stk = []

ans = 0

for string in s:
	if string == 'S':
		stk.append('S')

	else :
		if len(stk) != 0:
			stk.pop()

		else :
			ans += 1

print ans + len(stk)

