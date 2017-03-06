#!/bin/python3
'''
Largest Palindrome Product
https://www.hackerrank.com/contests/projecteuler/challenges/euler004
'''
import sys

'''
Pre-calculate all the palindromes
time complexity: O(899 + 898 + 897... + 1)

The list only contains around 600 unique members, 
which is not to hard to search for with a 
simple linear search
'''
def is_palindrome(num):
    if str(num)[::-1] == str(num):
        return True
    return False

palindromes = []
for i in range(101, 1000):
    for k in range(i, 1000):
        x = i*k
        if is_palindrome(x):
            palindromes.append(x)

palindromes.sort()
size = len(palindromes)

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    
    for palin in palindromes[::-1]:
        if n > palin:
            print(palin)
            break