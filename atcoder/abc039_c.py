import re

s = raw_input()
keys = ['Do','Do','Re','Re','Mi','Fa','Fa','So','So','La','La','Si']
keyboard = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW"

regex = (r'%s'%s)
pattern = re.compile(regex)

print keys[pattern.search(keyboard).start()%12]
