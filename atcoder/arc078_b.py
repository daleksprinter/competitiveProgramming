n = int(input())

edge = [[] for i in range(n)]

for i in range(n-1):
    f,t = map(int,raw_input().split())
    f -= 1
    t -= 1

    edge[f].append(t)
    edge[t].append(f)

inf = float("inf")
dist1 = [inf for i in range(n)]

dist1[0] = 0
stk = []
for i in edge[0]:
    stk.append([i,1])

while stk:
    t,c = stk.pop()
    if dist1[t] == inf :
        dist1[t] = c
        for i in edge[t]:
            stk.append([i,c+1])

dist2 = [inf for i in range(n)]
dist2[n-1] = 0
for i in edge[n-1]:
    stk.append([i,1])
while stk:
    t,c = stk.pop()
    if dist2[t] == inf :
        dist2[t] = c
        for i in edge[t]:
            stk.append([i,c+1])

fennec = 0
snuke = 0

for i in range(n):
    if dist1[i] <= dist2[i]:
        fennec += 1
    else :
        snuke += 1


if fennec > snuke:
    print "Fennec"
else:
    print "Snuke"
