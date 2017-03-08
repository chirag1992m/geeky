#!/bin/python3
'''
Summation of primes
https://www.hackerrank.com/contests/projecteuler/challenges/euler010
'''
import sys

N_max = 1000000

'''
Pre-calculate the primes until N given
'''
all_nums = [i for i in range(N_max + 1)]
primes = []

p = 2
while p <= N_max:
    primes.append(p)
    temp = 2*p
    while temp <= N_max:
        all_nums[temp] = 0
        temp += p
    p = p+1
    temp = p
    while temp <= N_max:
        if all_nums[temp]:
            break
        temp += 1
    p = temp

'''
If we simply linearly sum over the array
for the whole test case, it crosses the time limit
We, fix that by creating and augmented array of sums
of the primes

Using binary search, search over the prime array
and return the corresponding sum from the augmented array
'''
prime_sums = primes[:]
size = len(prime_sums)
run_sum = 0
for i in range(size):
    run_sum += prime_sums[i]
    prime_sums[i] = run_sum

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    if n == 1:
        print(0)
        continue
    
    start, mid, end = 0, size//2, size-1
    while start <= end:
        if primes[mid] == n:
            break
        elif primes[mid] > n:
            end = mid - 1
            mid = (start + end)//2
        else:
            start = mid + 1
            mid = (start + end)//2
    if primes[mid] > n:
        print(prime_sums[mid - 1])
    else :
        print(prime_sums[mid])