d,g = map(int,raw_input().split())

arr = []

for i in range(d):
	arr.append(map(int,raw_input().split()))


ans = float("inf")
for i in range(2**d-1,-1,-1):
	b = bin(i)[2:].zfill(d)
	count = 0
	point = 0
	for j in range(d-1,-1,-1):
		if b[j] == "1":
			count += arr[j][0]
			point += (j+1) * 100 * arr[j][0] + arr[j][1]
	if point < g:

		for j in range(d-1,-1,-1):

			if b[j] == "0":
				t = 0
				while point < g and arr[j][0]-t > 1:
					point += (j+1) * 100
					t += 1
					count += 1

	if point < g:
		continue
	ans = min(ans, count)

print ans


