#!/bin/python3
'''
Problem: Even Fibonacci numbers
https://www.hackerrank.com/contests/projecteuler/challenges/euler002
'''
import sys

'''
Fibonacci grows exponentially
So, there are not many fibonacci numbers less than (4 . 10^16)

We can easily save them in a list and sum them when required
'''
fib_list = []
N = 40000000000000000

counter = 0 #Every third number if an even number
x1 = 1
x2 = 2
while x2 <= N:
	if not counter:
		fib_list.append(x2)
	temp = x2 + x1
	x1 = x2
	x2 = temp

	counter = (counter + 1) % 3

T = int(input().strip())
for t in range(T):
	n = int(input().strip())

	even_sum = 0
	for num in fib_list:
		if num > n:
			break
		even_sum += num

	print(even_sum)