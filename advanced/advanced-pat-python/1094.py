__author__ = 'Zorro'
N, M = map(int, raw_input().split())
tree = {}
for i in xrange(M):
    line = map(int, raw_input().split())
    tree[line[0]] = line[2:]
import Queue
q = Queue.Queue()
q.put(1)
level, count = 0, 1
max_level, max_count = 1, 1
while not q.empty():
    count -= 1
    if count == 0:
        level += 1
        count = q.qsize()
        if count > max_count:
            max_count = count
            max_level = level
    t = q.get()
    for n in tree.get(t, []):
        q.put(n)
print max_count, max_level
