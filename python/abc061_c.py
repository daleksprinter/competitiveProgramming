n,k = map(int,raw_input().split())

arr = [0 for i in range(100001)]

for i in range(n):
	a,b = map(int,raw_input().split())
	arr[a] += b

i = 0
while k > 0 :
	i += 1
	k -= arr[i]
	

print i

