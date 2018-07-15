def mark(s, x):
    for i in xrange(x + x, len(s), x):
        s[i] = False

def sieve(n):
    s = [True] * n
    for x in xrange(2, int(n**0.5) + 1):
        if s[x]: mark(s, x)
    return [i for i in xrange(0,n) if s[i] and i > 1]

n = int(input())
ans = [i for i in sieve(55555) if i%5 == 1]

print ' '.join(map(str,ans[:n]))
