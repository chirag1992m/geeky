#!/bin/python3
'''
Largest product in a series
https://www.hackerrank.com/contests/projecteuler/challenges/euler008
'''
import sys

'''
K is very small
we can simply for every element of the number,
calculate product from i to i+k and keep a running maximum
Time complexity would still be in O(k)
'''
t = int(input().strip())
for a0 in range(t):
    n,k = input().strip().split(' ')
    n,k = [int(n),int(k)]
    num = input().strip()
    
    max_prod = 0
    for i in range(0, n-k):
        product = 1
        for j in range(k):
            product *= int(num[i+j])
        if max_prod < product:
            max_prod = product
    print(max_prod)