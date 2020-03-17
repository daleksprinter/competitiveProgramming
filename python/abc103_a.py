arr = map(int,raw_input().split())

arr.sort()

print abs(arr[1]- arr[0]) + abs(arr[2]- arr[1])
