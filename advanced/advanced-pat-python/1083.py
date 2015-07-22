N = int(raw_input())
stus = []
for i in xrange(N):
    name, id, grade = raw_input().split()
    grade = int(grade)
    stus.append((name, id, grade))
stus.sort(lambda s1, s2 : cmp(s2[-1], s1[-1]))
low, high = map(int, raw_input().split())
hasAny = False
for s in stus:
    if s[-1] >= low and s[-1] <= high:
        hasAny = True
        print s[0], s[1]
if not hasAny: print 'NONE'
