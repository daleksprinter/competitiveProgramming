n = int(input())

a = []
b = []

for i in range(n):
	at, bt = map(int,raw_input().split())

	a.append(at)
	b.append(bt)

ans = 0
for i in range(n-1,-1,-1):
	if (a[i] + ans) % b[i] == 0:
		next

	else :
		ans += (((a[i] + ans) / b[i]) + 1) * b[i] - (a[i] + ans)

print ans
