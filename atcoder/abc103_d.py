n,m = map(int,raw_input().split())

arr = []

for i in range(m):
	arr.append(map(int,raw_input().split()))

arr = sorted(arr, key=lambda x: x[1])


ans = 0
t = 0


for i in range(m):
	if arr[i][0] >= t:
		ans += 1
		t = arr[i][1]

print ans


