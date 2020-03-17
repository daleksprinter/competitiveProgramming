n = int(input())


arr = []
arr.append(0) 
arr.extend(map(int,raw_input().split()))
arr.append(0)

distance = 0
for i in range(n+1):
	distance += abs(arr[i + 1] - arr[i])

for i in range(0,n):
	print distance - (abs(arr[i + 1] - arr[i]) + abs(arr[i + 2] - arr[i + 1])) + abs(arr[i + 2] - arr[i])
