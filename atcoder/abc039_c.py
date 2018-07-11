import re

s = raw_input()
keys = ['Do','Do','Re','Re','Mi','Fa','Fa','So','So','La','La','Si']

key = "WBWBWWBWBWBW"

key *= 5

regex = (r'%s'%s)

pattern = re.compile(regex)

print keys[pattern.search(key).start()%12]


