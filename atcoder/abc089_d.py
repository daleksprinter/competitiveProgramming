h,w,d = map(int,raw_input().split())

field = []

for i in range(h):
	field.append(map(int,raw_input().split()))

distance = [0 for i in range(90001)]


n = int(input())

arr = [[] for i in range(90001)]

inputs = []

for i in range(n):
	inputs.append(map(int,raw_input().split()))


for i in range(h):
	for j in range(w):
		arr[field[i][j]] = [i+1,j+1]

for i in range(d+1,h*w+1):
	distance[i] = distance[i-d] + abs(arr[i][0] - arr[i-d][0]) + abs(arr[i][1] - arr[i-d][1])


for i in range(n):
	l,r = inputs[i]

	print distance[r]-distance[l]
