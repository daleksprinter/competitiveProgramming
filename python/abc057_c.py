n = int(input())

a = 1

def digitlen(i):
	t = i
	ret = 0	
	while t > 0 :
		t /= 10
		ret += 1
	return ret


ans = float("inf")

while a**2 <= n:
	if n%a == 0:
		b = n/a
		ans = min(ans, max(digitlen(a),digitlen(b)))

	a += 1

print ans

