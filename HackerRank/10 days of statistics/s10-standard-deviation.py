import math

n = int(input().strip())
X = [int(x) for x in input().split()]

mu = sum(X) / n

X = [(x - mu)*(x - mu) for x in X]

std = math.sqrt(sum(X) / n)

print('{:.1f}'.format(std))