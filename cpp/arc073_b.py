n, m = map(int,raw_input().split())

arr = [[] for i in range(4)]

w,v = map(int,raw_input().split())
arr[0].append(v)
arr[1].append(0)
arr[2].append(0)
arr[3].append(0)

for i in range(1,n):
	weight , value = map(int,raw_input().split())

	arr[weight - w].append(value)

ans = 0

for i in range(4):
	arr[i].sort()
	arr[i].reverse()


for i in range(len(arr[0])+1):
	for j in range(len(arr[1])+1):
		for k in range(len(arr[2])+1):
			for l in range(len(arr[3])+1):
				if i * w + j * (w+1) + k * (w+2) + l * (w+3) <= m:
					ans = max(ans,sum(arr[0][:i])+sum(arr[1][:j])+sum(arr[2][:k])+sum(arr[3][:l]))

print ans
