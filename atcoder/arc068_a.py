x = int(input())

ans = (x/11)*2
mod = x%11

if mod == 0 :
	print ans 
elif mod <= 6 :
	print ans + 1
else :
	print ans + 2
