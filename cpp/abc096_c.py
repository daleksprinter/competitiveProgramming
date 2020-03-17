import sys
h,w = map(int,raw_input().split())

arr = []

for i in range(h):
	arr.append(list(raw_input()))

field = [['.' for i in range(w)] for j in range(h)]

direct = [[0,-1],[1,0],[0,1],[-1,0]]

for i in range(h):
	for j in range(w):
		for k in range(4):
			dx = j + direct[k][1] 
			dy = i + direct[k][0]
			if -1 < dx and dx < w and -1 < dy and dy < h :
				if arr[i][j] == '#' and arr[dy][dx] == '#':
					field[i][j] = '#'
					field[dy][dx] = '#'

for i in range(h):
	for j in range(w):
		if arr[i][j] != field[i][j]:
			print 'No'
			sys.exit()

print 'Yes'

