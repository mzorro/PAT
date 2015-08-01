__author__ = 'Zorro'
MOD = 1000000007
s = raw_input()
l = len(s)
a, t = 0, 0
r = 0
for c in reversed(s):
    if c == 'P':
        r = (r + a) % MOD
    elif c == 'A':
        a = (a + t) % MOD
    elif c == 'T':
        t += 1
print r
