n = int(input())

arr6 = []
for i in range(10):
	arr6.append(6**i)

arr9 = []
for i in range(10):
	arr9.append(9**i)


ans = float("inf")
for i in range(n+1):
	count = 0
	tmp = i
	while tmp > 0:
		t = 0
		while arr6[t] <= tmp:
			t+=1

		tmp -= arr6[t-1]
		count += 1

	tmp = n-i
	while tmp > 0:
		t = 0
		while arr9[t] <= tmp:
			t += 1
		tmp -= arr9[t-1]
		count += 1

	ans = min(ans,count)

print ans
