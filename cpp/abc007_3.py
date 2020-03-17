r, c = map(int,raw_input().split())
sx , sy = map(int,raw_input().split())
sx -= 1
sy -= 1
gx , gy = map(int,raw_input().split())
gx -= 1
gy -= 1

field = [0 for i in range(r)]
inf = r*c*10
visited = [[inf for i in range(c)] for i in range(r)]

queue = []

for i in range(r):
	field[i] = list(raw_input())


queue.append([sx,sy])
visited[sy][sx] = 0
isfound = False

direct = [[0,-1],[1,0],[0,1],[-1,0]]

while len(queue) > 0 :

	coord = queue.pop()
	
	if coord[0] == gy and coord[1] == gx :
		isfound = True
		break

	else :
		for i in range(4):
			dx = coord[0] + direct[i][0]
			dy = coord[1] + direct[i][1]
			if -1 < dx and dx < c and -1 < dy and dy < r and visited[dy][dx] == inf and field[dy][dx] != '#' :
				visited[dy][dx] = visited[coord[1]][coord[0]] + 1
				queue.insert(0,[dx,dy])
				
print visited[gx][gy]
