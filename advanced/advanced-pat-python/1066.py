seq = map(int, raw_input().split())
N = seq.pop(0)
cnt = 0
vst = [False] * N

c = 0
for i in xrange(N):
    if i == seq[i]: vst[i] = True
    if vst[i]: continue
    c += 1
    j = i
    while not vst[j]:
        if seq[j] == 0: c -= 2
        vst[j] = True
        j = seq[j]
        c += 1
print c