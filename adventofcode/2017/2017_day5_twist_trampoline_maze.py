nums = [int(x) for x in open('input.txt', 'r').read().strip().split('\n')]

# Part 1

# limits_min = -1
# limits_max = len(nums)
# point = 0
# ans = 0
# while True:
#     jump = nums[point]
#     nums[point] += 1
#     point += jump
#     ans += 1
#     if point <= limits_min or point >= limits_max:
#         break
#
# print(ans)

# Part 2

limits_min = -1
limits_max = len(nums)
point = 0
ans = 0
while True:
    jump = nums[point]
    if nums[point] >= 3:
        nums[point] -= 1
    else:
        nums[point] += 1
    point += jump
    ans += 1
    if point <= limits_min or point >= limits_max:
        break

print(ans)
