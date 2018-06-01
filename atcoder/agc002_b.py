n,m = map(int,raw_input().split())

arr = [1 for i in range(n)]
isexist = [False for i in range(n)]

isexist[0] = True

for i in range(m):
	frm,to = map(int,raw_input().split())
	frm -= 1
	to -= 1

	arr[frm] -= 1
	arr[to] += 1

	if isexist[frm] :
		isexist[to] = True

	if arr[frm] == 0:
		isexist[frm] = False




count = 0
for i in range(n):
	if isexist[i] : 
		count += 1

print count
