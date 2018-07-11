n = int(input())

arr = map(int,raw_input().split())

arrb = []

for i in range(n):
	arrb.append([arr[i],i+1])

arrb.sort()

for i in range(n-1,-1,-1):
	print arrb[i][1]
