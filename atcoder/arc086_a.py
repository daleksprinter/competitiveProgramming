import Queue
n,k = map(int,raw_input().split())
arr = map(int,raw_input().split())

counts = {}
for i in arr:
	if i not in counts:
		counts[i] = 1
	else :
		counts[i] += 1

queue = Queue.PriorityQueue()

for i in counts.values():
	queue.put(i)

ans = 0
while queue.qsize() > k :
	ans += queue.get()

print ans
