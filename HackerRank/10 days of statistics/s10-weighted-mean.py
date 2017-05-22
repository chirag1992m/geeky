n = int(input().strip())
X = [int(x) for x in input().split()]
W = [int(w) for w in input().split()]

num = 0
den = 0
for i in zip(X, W):
    num += i[0] * i[1]
    den += i[1]

print("{:.1f}".format(num/den))