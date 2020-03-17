import copy
import Queue
h,w ,t = map(int,raw_input().split())

arr = [raw_input() for i in range(h)]


def dijkstra(start, num_of_node, adjacent_list):
	#initialize
	dist = [float("inf") for i in range(num_of_node)]
	dist[start] = 0
	q = Queue.PriorityQueue()
	q.put((dist[start], start))

	while not q.empty():
		dist_u, u = q.get()

		if dist[u] < dist_u :
			continue

		for weight,v in adjacent_list[u]:
			alt = dist_u + weight
			if dist[v] > alt:
				dist[v] = alt
				q.put((alt,v))

	return dist

s = 0
g = 0
for i in range(h):
	for j in range(w):
		if arr[i][j] == 'S':
			s = (i,j)
		elif arr[i][j] == 'G':
			g = (i,j)

directs = [(-1,0), (0,-1), (1,0), (0,1)]

def to_node(c):
	return c[0] * w  + c[1] 

def istrue(x):
	al = [[] for i in range(h*w)]
	for i in range(h): # set adjacent list
		for j in range(w):
				for xdir, ydir in directs:
					dx = j + xdir; dy = i + ydir
					if -1 < dx < w and -1 < dy < h:
						if arr[dy][dx] == '#':
							al[to_node((i,j))].append((x,to_node((dy,dx))))
						else :
							al[to_node((i,j))].append((1,to_node((dy,dx))))
	return True if dijkstra(to_node(s), h*w, al)[to_node(g)] <= t else False

left = 0; right = t
for i in range(30):
	mid = (left + right)/2
	if istrue(mid):
		left = mid
	else :
		right = mid

print left
