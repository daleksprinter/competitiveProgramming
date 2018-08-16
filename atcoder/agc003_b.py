n = int(input())

arr = []

for i in range(n):
	arr.append(int(input()))

l = 0
r = 0


ans = 0
while l < n:
	while  r+1 < n and arr[r+1] > 0:
		r += 1

	ans += sum(arr[l:r+1])/2
	l = r+1
	r = l

print ans


