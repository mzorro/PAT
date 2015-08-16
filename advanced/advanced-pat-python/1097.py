__author__ = 'Zorro'
__link__ = 'http://www.patest.cn/contests/pat-a-practise/1097'
__input__ = """00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854""".split('\n')
_call_times = -1
def raw_input():
    global _call_times
    _call_times += 1
    return __input__[_call_times]

# now the code begins
import math
lst = [-1] * 100000
val = [0] * 100000
root, N = map(int, raw_input().split())
for i in xrange(N):
    a1, v, a2 = map(int, raw_input().split())
    lst[a1] = a2
    val[a1] = v
dup = []
p = root
new_lst, new_root, new_last = {}, -1, -1
del_lst, del_root, del_last = {}, -1, -1
while p != -1:
    a = int(math.fabs(val[p]))
    if a in dup:
        if del_last == -1:
            del_root = p
        else:
            del_lst[del_last][1] = p
        del_last = p
        del_lst[del_last] = [val[p], -1]
    else:
        dup.append(a)
        if new_last == -1:
            new_root = p
        else:
            new_lst[new_last][1] = p
        new_last = p
        new_lst[new_last] = [val[p], -1]
    p = lst[p]
p = new_root
while p != -1:
    print "%05d" % p, new_lst[p][0],
    p = new_lst[p][1]
    print -1 if p == -1 else "%05d" % p
p = del_root
while p != -1:
    print "%05d" % p, del_lst[p][0],
    p = del_lst[p][1]
    print -1 if p == -1 else "%05d" % p
