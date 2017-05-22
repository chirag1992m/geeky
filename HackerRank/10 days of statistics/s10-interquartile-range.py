n = int(input().strip())
X = [int(x) for x in input().split()]
F = [int(x) for x in input().split()]

S = []
for i in zip(X, F):
    S.extend([i[0]] * i[1])
S.sort()
n = len(S)
    
def median(x):
    l = len(x)
    if l%2 == 0:
        return (x[(l-2)//2] + x[l//2])/2
    else:
        return x[(l-1)//2]

Q1 = median(S[:n//2])
if n%2 == 0:
    Q3 = median(S[n//2:])
else:
    Q3 = median(S[(n+1)//2:])

print("{:.1f}".format(Q3 - Q1))