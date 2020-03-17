n = int(input())

arr = map(int,raw_input().split())

colors = [0] * 8
ans = 0

for i in arr:
	t = i/400
	if t < 8:
		colors[t] += 1

	else:
		ans += 1

col = 0
for i in colors:
	if i > 0:
		col += 1
if col == 0 and ans > 0 :
	print col+1 , ans 
	quit()
	
print col, col + ans



