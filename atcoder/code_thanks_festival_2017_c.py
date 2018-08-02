import Queue
n,k = map(int,raw_input().split())

q = Queue.PriorityQueue()

ans = 0
for i in range(n):
	q.put(map(int,raw_input().split()))

while k > 0:
	tmp = q.get()
	ans += tmp[0]
	tmp[0] += tmp[1]
	q.put(tmp)
	k -= 1

print ans
