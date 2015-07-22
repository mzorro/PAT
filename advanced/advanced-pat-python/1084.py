s1 = raw_input().upper()
s2 = raw_input().upper()

i1 = i2 = 0
missing = []
while i1 < len(s1) and i2 < len(s2):
    if s1[i1] != s2[i2]:
        if not s1[i1] in missing:
            missing.append(s1[i1])
        i1 += 1
    else:
        i1 += 1
        i2 += 1
if i1 < len(s1):
    if not s1[i1] in missing:
        missing.append(s1[i1])
    i1 += 1
print ''.join(missing)