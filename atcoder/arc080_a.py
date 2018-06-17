n = int(input())

arr = map(int,raw_input().split())

dic = [0,0,0]

for i in arr:
	if i%4==0:
		dic[2] += 1
	elif i%2 == 0:
		dic[1] += 1
	else :
		dic[0] += 1


if dic[2]+1 <= dic[0] and 0 < dic[1]:
	print 'No'
elif dic[2]+1 == dic[0] and dic[1] == 0:
	print 'Yes'

elif dic[2] >= dic[0] :
	print 'Yes'

else :
	print 'No'
