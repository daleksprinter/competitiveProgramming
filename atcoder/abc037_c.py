n,k = map(int,raw_input().split())

arr = map(int,raw_input().split())

cumulative_sum = []

s = 0
cumulative_sum.append(0)

for i in range(n):
	cumulative_sum.append(s+arr[i])
	s += arr[i]

ans = 0
for i in range(k,n+1):
	ans += (cumulative_sum[i]-cumulative_sum[i-k])

print ans

