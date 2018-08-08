n = raw_input()
l = len(n)

ans = 0

t = 2**(l-1)

if l == 1:
	print n
	quit()

for i in range(t):
	bit = (bin(i)[2:]).zfill(l-1)
	formula = ''

	p = 0
	b = 0

	while b < len(bit):
		formula += n[p]
		formula += "+" if bit[b] == "1" else ""
		p += 1
		b += 1

	formula += n[-1]
	ans += eval(formula)

print ans
