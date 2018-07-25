n = int(input())
arr = map(int,raw_input().split())

n4 = 0
n1 = 0
for i in arr:
	if i%4 == 0 :
		n4 += 1
	elif i%2 == 1:
		n1 += 1

if len(arr) - n4 - n1 > 0 :
	if n4 >= n1 :
		print "Yes"
	else :
		print "No"

else :
	if n4 >= n1 - 1:
		print "Yes"
	else :
		print "No"
