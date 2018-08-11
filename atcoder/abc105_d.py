import collections

n,m = map(int,raw_input().split())

arr = map(int,raw_input().split())

sums = []
sums.append(arr[0]%m)

for i in range(1,n):
	sums.append((sums[i-1] + arr[i])%m)



c = collections.Counter(sums)
ans = 0
ans += sums.count(0)
for i in c.values():
	ans += i*(i-1)/2

print ans
