arr = map(int,raw_input().split())

l1 = min(arr[0]*4,arr[1]*2,arr[2])
l2 = min(l1*2,arr[3])
n = int(input())

ans = n/2*l2 + n%2 * l1
print ans



