#!/bin/python3
'''
10001st prime
https://www.hackerrank.com/contests/projecteuler/challenges/euler007
'''
import sys

'''
Pre calculate atleast 10000 primes
which doesn't take much time.
Just give the N'th prime number for every test case
'''
MAX_bound = 110000 # pre-calculated with experimentations

#Sieve of Erastohthenes
prime_temp = [i for i in range(0, MAX_bound+1)]
primes = []

p = 2
size = len(prime_temp)
while p < size:
    primes.append(prime_temp[p])
    itr = p*2
    while itr < size:
        prime_temp[itr] = -1
        itr += p
    
    p = p+1
    itr = p
    while itr < size:
        if prime_temp[itr] != -1:
            break
        itr = itr+1
    p = itr

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    print(primes[n-1])