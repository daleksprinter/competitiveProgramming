h,w = map(int,raw_input().split())

n = int(input())

arr = map(int,raw_input().split())

field = [[0 for i in range(w)] for j in range(h)]


x = 0
y = 0
d = 1
p = 0

for i in range(h*w):

	if arr[p] == 0:
		p += 1

	field[y][x] = str(p + 1)
	arr[p] -= 1

	x = x + d
	if x == -1 or x == w:
		x -= d
		y += 1
		d *= -1

for i in range(h):
	print ' '.join(field[i])

