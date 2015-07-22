__author__ = 'Zorro'
N, p = map(int, raw_input().split())
nums = map(int, raw_input().split())
nums.sort()
size = len(nums)
l, r, res = -1, 0, 0
while r < size:
    l += 1
    while r < size and nums[r] <= nums[l]*p: r += 1
    res = max(res, r - l)
print res