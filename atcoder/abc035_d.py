import Queue

n, m, t = map(int,raw_input().split())

treasures = map(int,raw_input().split())

tolist = [[] for i in range(n)]
backlist = [[] for i in range(n)]

for i in range(m):
	frm, to, cost = map(int,raw_input().split())
	frm -= 1; to -= 1

	tolist[frm].append((cost, to))
	backlist[to].append((cost, frm))

def dijkstra(start, num_of_node, adjacent_list):
	#initialize
	dist = [float("inf") for _ in xrange(num_of_node)]
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

todist = dijkstra(0, n, tolist)
backdist = dijkstra(0, n, backlist)

times = [todist[i] + backdist[i] for i in xrange(n)]
ans = -1
for i in range(n):
	ans = max(ans, (t-times[i]) * treasures[i])

print ans

