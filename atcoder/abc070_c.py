def gcd(a,b):
	if b == 0 :
		return a
	else :
		return gcd(b,a%b)
 
def lcm(a,b):
	return a*b/gcd(a,b)
 
n = int(input())
arr = []
for i in range(n):
 
	arr.append(int(input()))
 
 
def mlcm():
 	if n == 1:
 		return arr[0]

	ans = lcm(arr[0],arr[1])
 
	i = 2
	while i<n:
		ans = lcm(ans,arr[i])
		i+=1
 
	return ans
 
print mlcm()
