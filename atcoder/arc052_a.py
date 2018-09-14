import re

s = raw_input()

regexp = r'\d{1}\d?'

find = re.findall(regexp,s)

print find[0]


