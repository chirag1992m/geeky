#!/bin/python3
'''
Sum Square Difference
https://www.hackerrank.com/contests/projecteuler/challenges/euler006
'''

import sys

'''
It asks the following difference:
((\sum_{i=1}^{i=N}{i})^2 - (\sum_{i=1}^{i=N}{i^2}))
= (n^2 * (n+1)^2 / 4) - ((n*(n+1)*(2n+1))/6)
which reduces to the following get_difference method

Difference of sum of squares and square of sum
'''
def get_difference(N):
    return (N * (N+1) * ((3*N*N) - N -2))//12

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    print(get_difference(n))