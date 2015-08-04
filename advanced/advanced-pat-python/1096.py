__author__ = 'Zorro'
__link__ = 'http://www.patest.cn/contests/pat-a-practise/1096'
__input__ = """29""".split('\n')
_call_times = -1
def raw_input():
    global _call_times
    _call_times += 1
    return __input__[_call_times]

# now the code begins
import math
N = int(raw_input())
l, r = 2, 2
cl, cr = 0, 0
n = N
M = math.ceil(math.sqrt(N))
while r <= M:
    while n % r == 0:
        n /= r
        r += 1
    if r - l > cr - cl:
        cr, cl = r, l
    if l >= r:
        r = l = l + 1
    else:
        n *= l
        l += 1
if cr == 0:
    print 1
    print N
else:
    print cr - cl
    s = ""
    for x in xrange(cl, cr-1):
        s += str(x) + "*"
    print s + str(cr-1)
