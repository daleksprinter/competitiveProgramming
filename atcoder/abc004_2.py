arr = [[] for i in range(4)]
ans = [['' for j in range(4)] for i in range(4)]

for i in range(4):
	arr[i] = raw_input().split()


for i in range(4):
	for j in range(4):
		ans[i][j] = arr[3-i][3-j]

for i in range(4):
	print '%s %s %s %s' %(ans[i][0],ans[i][1],ans[i][2],ans[i][3])


