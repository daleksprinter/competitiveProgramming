n = int(input())

arr = []

for i in range(n):
	arr.append(int(input()))

arr.sort()

ans = sum(arr)

if ans%10 == 0:
	ind = 0
	while  ind < n and arr[ind] % 10 == 0:
		ind += 1

	if ind == n:
		print 0

	else :
		print ans - arr[ind]
else:
	print ans
