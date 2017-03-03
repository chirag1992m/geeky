#!/bin/python3
'''
Problem: Multiples of 3 and 5
https://www.hackerrank.com/contests/projecteuler/challenges/euler001
'''
import sys

'''
Logic:
summation of multiples of 3 (x=3): 1x + 2x + 3x + 4x + 5x... until yx < N => x(1+2+3...)
summation of multiples of 5 (x=5): 1x + 2x + 3x + 4x + 5x... until yx < N => x(1+2+3...)

Add both.

Remove multiples of 3 and 5 both. that is multiples of 15.

Final answer = summation of multiples of 3 + summation of multiples of 5 - summation of multiples of 15
'''
def get_multiples_sum(x, N):
	y = (N-1)//x
	return (y * (y+1)//2)*x

if __name__ == "__main__":
	t = int(input().strip())
	for a0 in range(t):
		n = int(input().strip())

		sum_3 = get_multiples_sum(3, n)
		sum_5 = get_multiples_sum(5, n)
		sum_15 = get_multiples_sum(15, n)

		ans = sum_3 + sum_5 - sum_15

		print(ans)