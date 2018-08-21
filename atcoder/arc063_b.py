n,t = map(int,raw_input().split())

arr = map(int,raw_input().split())

mintable = []
m = float("inf")
for i in arr :
	mintable.append(min(m,i))
	m = min(m,i)

ma = float("-inf")
for i in range(n):
	ma = max(ma,arr[i] - mintable[i])
ans = 0
for i in range(n):
	if arr[i] - mintable[i] == ma:	
		ans += 1

print ans
