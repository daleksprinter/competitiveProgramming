n,k = map(int,raw_input().split())

arr = []

for i in range(n):
	arr.append(int(input()))

if 0 in arr:
	print n

else :
	ans = 0
	right = 0
	product = 1
	for left in range(n) :
		while right < n and product * arr[right] <= k :
			product *= arr[right]
			right += 1

		ans = max(ans,right - left)

		if right == left :
			right += 1
		else :
			product /= arr[left]

	print ans

