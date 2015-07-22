N = input()
for i in xrange(N):
    A, B, C = map(int, raw_input().split())
    print 'Case #%d:' % (i+1),
    print 'true' if (A + B > C) else 'false'