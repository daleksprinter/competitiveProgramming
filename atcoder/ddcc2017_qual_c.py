n,c = map(int,raw_input().split())

arr = []

for i in range(n):
	arr.append(int(input()))

arr.sort()

l = 0
r = n-1
ans = 0

while l < r:
	if arr[r] + arr[l] + 1 <= c:
		ans += 1
		l += 1
		r -= 1

	else :
		ans += 1
		r -= 1

print ans + 1 if l == r else ans 
