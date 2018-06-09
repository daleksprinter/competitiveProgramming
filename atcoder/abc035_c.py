n,q = map(int,raw_input().split())

arr = [0 for i in range(n)]
arr_sum = []

for i in range(q):
	l,r = map(int,raw_input().split())
	arr[l-1] += 1
	if r != n: 
		arr[r] -= 1

arr_sum.append(arr[0])
for i in range(1,n):
	arr_sum.append(arr_sum[i-1]+arr[i])

ans = ''
for i in range(n):
	ans += str(arr_sum[i]%2)

print ans
