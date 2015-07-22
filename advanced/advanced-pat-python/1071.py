s = raw_input()
s = list(s.lower())
for i in xrange(len(s)):
    if not('0' <= s[i] <= '9'\
       or 'a' <= s[i] <= 'z' \
       or 'A' <= s[i] <= 'Z'):
        s[i] = ' '
s = ''.join(s).split()
dic = {}
for word in s:
    dic.setdefault(word, 0)
    dic[word] += 1
def compare(a1, a2):
    if a1[1] == a2[1]:
        return cmp(a1[0], a2[0])
    else:
        return cmp(a2[1], a1[1])
for word, cnt in sorted(dic.items(), compare):
    print word, cnt
    break