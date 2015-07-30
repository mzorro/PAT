__author__ = 'Zorro'
src = raw_input()
need = raw_input()
have = {}
for s in src:
    have[s] = have.get(s, 0) + 1
missing = 0
for n in need:
    if have.get(n, 0) == 0:
        missing += 1
    else:
        have[n] -= 1
if not missing:
    print "Yes", len(src) - len(need)
else:
    print "No", missing
