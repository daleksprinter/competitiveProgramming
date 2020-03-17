n,m = map(int,raw_input().split())

arr = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
	x,y = map(int,raw_input().split())
	x -= 1; y -= 1

	arr[x][y] = 1
	arr[y][x] = 1

ans = -1
for i in range(2**n):
	b = bin(i)[2:].zfill(n)
	count = 0
	for j in range(n):
		for k in range(n):
			if j != k and b[j] == "1" and b[k] == "1" and arr[j][k] == 1:
				count += 1
	t = b.count("1")
	if count == sum(range(t))*2:
		ans = max(ans,t)

print ans if ans > 0 else 1
