__author__ = 'Zorro'
__link__ = 'http://www.patest.cn/contests/pat-a-practise/1100'
__input__ = """
4
0
5
tret
tam
""".strip().split("\n")
_call_times = -1
def raw_input():
    global _call_times
    _call_times += 1
    return __input__[_call_times]

marsNum = [
    "tret, jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec".split(", "),
    "tret, tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou".split(", ")
]
def earth_to_mars(s):
    res = []
    n = int(s)
    first = True
    while n > 0:
        t = n % 13
        n /= 13
        if first:
            first = False
            if t != 0:
                res.append(marsNum[0][t])
        else:
            res.append(marsNum[1][t])
    if len(res) == 0:
        res.append("tret")
    return " ".join(reversed(res))

def mars_to_earth(s):
    nums = s.split(" ")
    res = 0
    last_from_1 = 0
    for num in nums:
        res *= 13
        try:
            n = marsNum[0].index(num)
            last_from_1 = 0
        except ValueError:
            n = marsNum[1].index(num)
            last_from_1 = 1
        res += n
    res *= 13 ** last_from_1
    return res

N = int(raw_input())
inputs = []
for i in xrange(N):
    inputs.append(raw_input())
for line in inputs:
    if line.isdigit():
        print earth_to_mars(line)
    else:
        print mars_to_earth(line)
