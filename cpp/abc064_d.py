
n = int(input())

s = list(raw_input())
stk = []

i = 0
while i<len(s):
	if s[i] == ')' and not stk:
		s.insert(0,"(")
		i += 1

	if s[i] == ')' and  stk:
		stk.pop()

	if s[i] == '(':
		stk.append('(')
	i += 1

for i in range(len(stk)):
	stk[i] = ')'

print ''.join(s) + ''.join(stk)

