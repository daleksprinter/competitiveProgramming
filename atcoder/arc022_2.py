n = int(input())

arr = map(int,raw_input().split())

l = 0
r = 0
ans = 0

s = set()
while r < n:
	if not arr[r] in s:
		s.add(arr[r])
		r += 1
		ans = max(ans, r-l+1)

	else :
		while arr[l] != arr[r]:
			s.remove(arr[l])
			l += 1
		l += 1
		r += 1


print ans-1
