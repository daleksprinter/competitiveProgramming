import collections
n = int(input())

arr = map(int,raw_input().split())

deque = collections.deque()

for i in range(n):
	if i % 2 == 0:
		deque.appendleft(arr[i])

	else :
		deque.append(arr[i])

for i in range(n) :
	arr[i] = str(deque.pop())

if i % 2 == 1:
	print ' '.join(arr)

else :
	print ' '.join(reversed(arr))
