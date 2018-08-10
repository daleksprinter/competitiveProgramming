n, c = map(int,raw_input().split())

arr = [[0 for i in range(c)] for j in range(10**5+1)]

for i in range(n):
	s,t,ch = map(int,raw_input().split())
	s -= 1
	ch -= 1
	for i in range(s,t):
		arr[i][ch] = 1

ans = 0

for i in range(10**5+1):
	ans = max(ans,sum(arr[i]))

print ans
