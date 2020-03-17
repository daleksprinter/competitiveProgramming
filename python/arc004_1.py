import math

num = int(raw_input())

arr = [[0 for column in range(2)] for row in range(num)]


for i in range(num):
	line = map(int,raw_input().split())
	arr[i][0] = line[0]
	arr[i][1] = line[1]

max = 0.0

for i in range(num):
	for j in range(num):
		dist = math.sqrt((arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]) + (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]))
		if max < dist : 
			max = dist

print max
