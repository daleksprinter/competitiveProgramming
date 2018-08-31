t = int(input())

n = int(input())

import Queue

q = Queue.PriorityQueue()

tmp = map(int,raw_input().split())

for i in tmp:
	q.put(i)

m = int(input())

arr = map(int,raw_input().split())

i = 0
while i < m:
	issold = False
	while not q.empty():
		tako = q.get()

		if tako > arr[i] :
			print 'no'
			quit()

		if tako >= arr[i] - t :
			issold = True
			break
	if issold :
		i += 1

	if q.empty() and i < m:
		print 'no'
		quit()

	

print 'yes'

