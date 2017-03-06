#!/bin/python3
'''
Smallest Multiple
https://www.hackerrank.com/contests/projecteuler/challenges/euler005
'''

import sys
'''
Smallest multiple of numbers from 1 to N
would be the multiple of primes from 1 to N
using their highest multiplicity < N

For eg: LCM of 1 to 10 = 2520 = 2^3 * 3^2 * 5 * 7
'''

#Store all the primes less than 40 beforehand
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

#Get highest multiplicity
def get_max_multiple(prime, N):
    product = 1
    while product <= N:
        product *= prime
    product = product//prime
    return product

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    product = 1
    for prime in primes:
        if prime > n:
            break
        product *= get_max_multiple(prime, n)
    print(product)