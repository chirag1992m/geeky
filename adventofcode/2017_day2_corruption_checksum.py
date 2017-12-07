# Part 1
nums = [[int(y) for y in x.strip().split('\t')] for x in open('input.txt').readlines()]

ans = 0

for line in nums:
    ans += (max(line) - min(line))

print(ans)

# Part 2
nums = [sorted([int(y) for y in x.strip().split('\t')], reverse=True) for x in open('input.txt').readlines()]

ans = 0

for line in nums:
    flag = False
    for i in range(len(line)):
        if flag:
            break
        for j in range(i+1, len(line)):
            if flag:
                break
            if line[i] % line[j] == 0:
                ans += line[i] / line[j]
                flag = True

print(ans)
