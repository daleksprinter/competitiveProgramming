import numpy as np
n,m = map(int,raw_input().split())

print int(np.ceil(float(n)/m) - n/m)
