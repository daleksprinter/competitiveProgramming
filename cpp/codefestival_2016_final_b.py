n = int(input())

ans = 0
i = 1

while n > ans:
	ans += i
	i += 1

sums = sum(range(i))
diff = sums - n

for j in range(1,i):
	if j != diff:
		print j
