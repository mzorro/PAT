__author__ = 'Zorro'
__link__ = 'http://www.patest.cn/contests/pat-a-practise/1095'
__input__ = """16 7
JH007BD 18:00:01 in
ZD00001 11:30:08 out
DB8888A 13:00:00 out
ZA3Q625 23:59:50 out
ZA133CH 10:23:00 in
ZD00001 04:09:59 in
JH007BD 05:09:59 in
ZA3Q625 11:42:01 out
JH007BD 05:10:33 in
ZA3Q625 06:30:50 in
JH007BD 12:23:42 out
ZA3Q625 23:55:00 in
JH007BD 12:24:23 out
ZA133CH 17:11:22 out
JH007BD 18:07:01 out
DB8888A 06:30:50 in
05:10:00
06:30:50
11:00:00
12:23:42
14:00:00
18:00:00
23:59:00""".split('\n')
_call_times = -1
def raw_input():
    global _call_times
    _call_times += 1
    return __input__[_call_times]

# now the code begins
t2i = lambda t: reduce(lambda x, y: x*60 + y, map(int, t.split(':')))
M, Q = map(int, raw_input().split())
records = []
for i in xrange(M):
    r = raw_input().split()
    r[1] = t2i(r[1])
    r[2] = 1 if r[2] == 'in' else -1
    records.append(r)
last = records[0]
new_records = []
records.sort()
intervals = {}
max_interval = 0
max_cars = []
for i in xrange(1, len(records)):
    last = records[i-1]
    curr = records[i]
    if last[0] == curr[0] and last[2] == 1 and curr[2] == -1:
        new_records.append(last)
        new_records.append(curr)
        interval = intervals[last[0]] = intervals.get(last[0], 0) + curr[1] - last[1]
        if max_interval == interval:
            max_cars.append(last[0])
        elif max_interval < interval:
            max_cars = [last[0]]
            max_interval = interval

records = new_records
records.sort(lambda x, y: cmp(x[1], y[1]))
index = 0
count = 0
for i in xrange(Q):
    time = t2i(raw_input())
    while index < len(records) and records[index][1] <= time:
        count += records[index][2]
        index += 1
    print count

for car in sorted(max_cars):
    print car,
mi = max_interval
print "%02d:%02d:%02d" % (mi / 3600, mi % 3600 / 60, mi % 60)
