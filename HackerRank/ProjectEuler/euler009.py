#!/bin/python3
'''
Special Pythagorean Triplet
https://www.hackerrank.com/contests/projecteuler/challenges/euler009
'''
import sys

'''
Given,
a + b + c = N
a^2 + b^2 = c^2
a, b, c are integers

Solving the three equations give,
c = N - a - b
b = (N^2 - 2Na)/2(N-a)
for b to be integer, the denominator should be a 
divisor of numerator
'''
def generate_abc(N):
    a_max = (N+1)//2
    for a in range(1, a_max):
        num = (N*N) - (2*N*a)
        den = 2*(N-a)
        if num%den == 0:
            b = num//den
            c = N - a - b
            yield a*b*c

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    max_prod = -1
    for prod in generate_abc(n):
        if prod > max_prod:
            max_prod = prod
    print(max_prod)