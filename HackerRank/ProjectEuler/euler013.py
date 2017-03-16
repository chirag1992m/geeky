'''
Large Sum
https://www.hackerrank.com/contests/projecteuler/challenges/euler013
'''

'''
Actually python took out all the fun out
of the problem as it can handle arbitrarily
large integers with ease

So, just sum up the numbers. Convert it to
string and show the first 10 characters of the
string 
'''
totalSum = 0

N = int(input().strip())
for i in range(N):
    num = int(input().strip())
    totalSum += num
    
totalSum = str(totalSum)
print(totalSum[:10])