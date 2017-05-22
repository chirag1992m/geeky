n = int(input().strip())
arr = [int(x) for x in input().split()]
arr.sort()

if n%2 == 0:
    median = (arr[(n//2) - 1] + arr[n//2]) /2
else:
    median = arr[(n-1)//2]

mode = arr[0]
mean = arr[0]
best_count = 1
count = 1
prev = arr[0]

for i in range(1, n):
    if arr[i] == prev:
        count += 1
    else:
        prev = arr[i]
        count = 1
        
    if best_count < count:
        best_count = count
        mode = prev
    mean += arr[i]
    
mean = mean/n

print("{:.1f}".format(mean))
print("{:.1f}".format(median))
print(mode)