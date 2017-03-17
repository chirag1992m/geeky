'''
Power digit sum
https://www.hackerrank.com/contests/projecteuler/challenges/euler016
'''
'''
As usual python can easily handle
arbitrarily large integers so 
we can just multiply powers of two
and sum up the digits
'''

N_max = 10000
powers = [1] * (N_max + 1)

for i in range(1, N_max + 1):
    powers[i] = 2*powers[i-1]

T = int(input().strip())
for t in range(T):
    n = int(input().strip())
    
    digits = [int(digit) for digit in list(str(powers[n]))]
    print(sum(digits))