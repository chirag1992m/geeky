#!/bin/python3
'''
Largest Prime Factor
https://www.hackerrank.com/contests/projecteuler/challenges/euler003
'''
import sys

'''
Divisors will generally go till sqrt(N)

Pre-calculate prime numbers using sieve of erastosthenes

Given n,
1. Find a prime number p which divides n (candidate prime found)
2. divide n by p^m where m is the max multiplicity
3. If n is still not 1, go back to step 1
4. If all the primes are exhausted, the remaining n is a prime itself.
5. Compare n with the largest prime already found ad print answer
'''

MAX_number = 1000000000000
MAX_divisor = 1000001 # approximately = sqrt(MAX_number)

#Sieve of Erastohthenes
prime_temp = [i for i in range(0, MAX_divisor+1)]
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
    
    ans = 1
    for p in primes:
        if p > n:
            break
        if n%p == 0: #Find p
            ans = max(ans, p)
            while n%p == 0:
                n = n//p #Divide by multiplicity
    ans = max(ans, n) #if n is not 1, remaining n is a prime itself
    print(ans)