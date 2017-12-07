# Part 1
nums = open('input.txt', 'r').read().strip()

ans = 0

for i in range(len(nums)):
    next_num = (i + 1) % len(nums)
    if nums[i] == nums[next_num]:
        ans += int(nums[i])

print(ans)


# Part 2
nums = open('input.txt', 'r').read().strip()

ans = 0

for i in range(len(nums)):
    next_num = (i + (len(nums)//2)) % len(nums)
    if nums[i] == nums[next_num]:
        ans += int(nums[i])

print(ans)
