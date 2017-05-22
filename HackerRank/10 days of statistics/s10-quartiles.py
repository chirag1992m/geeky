n = int(input().strip())
arr = [int(x) for x in input().split()]
arr.sort()

def median(x):
    l = len(x)
    if l%2 == 0:
        return int((x[(l-2)//2] + x[l//2])/2)
    else:
        return x[(l-1)//2]

Q2 = median(arr)
Q1 = median(arr[:n//2])
if n%2 == 0:
    Q3 = median(arr[n//2:])
else:
    Q3 = median(arr[(n+1)//2:])

print(Q1)
print(Q2)
print(Q3)