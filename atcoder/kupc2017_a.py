n,k = map(int,raw_input().split())


arr = map(int,raw_input().split())

arr.sort()
arr.reverse()

ans = 0
i= 0
while k > 0 and i < n:
	k -= arr[i]
	ans += 1
	i+=1

print ans if k <= 0 else -1
