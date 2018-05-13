num,yen = map(int,raw_input().split())

ans = [-1,-1,-1]
isanswered = False

if 10000*num >= yen: 
	for i in range(num+1):
		for j in range(num+1-i):
			if 10000*i + 5000*j + 1000*(num-i-j) == yen and num-i-j-(num-i-j) == 0:
				ans[0] = i
				ans[1] = j
				ans[2] = (num-i-j)
				isanswered = True
				break

		if isanswered == True :
			break

print '%d %d %d' %(ans[0],ans[1],ans[2])

