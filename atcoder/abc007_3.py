h ,w = map(int,raw_input().split())

sy, sx = map(int,raw_input().split())

gy, gx = map(int,raw_input().split())

arr = [raw_input() for i in range(h)]

inf = float("inf")
distance = [[inf for i in range(w)] for j in range(h)]
distance[sy-1][sx-1] = 0
queue = [[sy-1,sx-1,0]]
direct = [[0,-1],[1,0],[0,1],[-1,0]]

while queue :
	ty, tx, cost = queue.pop(0)

	if ty == gy-1 and tx == gx-1 :
		print  distance[ty][tx]
		quit()

	for y,x in direct :
		dy = ty + y
		dx = tx + x

		if -1 < dy < h and -1 < dx < w and arr[dy][dx] == '.' and distance[dy][dx] == inf :
			distance[dy][dx] = cost + 1
			queue.append([dy,dx,cost + 1])


