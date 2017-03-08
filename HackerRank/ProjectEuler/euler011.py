#!/bin/python3
'''
Largest Product in a grid
https://www.hackerrank.com/contests/projecteuler/challenges/euler011
'''
import sys

'''
Logic: Brute-Force Method!
But, you don't have to go through left, up, and 
two more diagonals as they would be covered by a 
different entry in the grid's righ, down, and other
two diagonals
'''
def down(i, j):
    return i+3 < 20

def right(i, j):
    return j+3 < 20

def diagonal_1(i, j):
    return (j+3 < 20 and i+3 < 20)

def diagonal_2(i, j):
    return (j-3 >= 0 and i+3 < 20)

grid = []
for grid_i in range(20):
   grid_t = [int(grid_temp) for grid_temp in input().strip().split(' ')]
   grid.append(grid_t)
    
max_prod = 0
for i in range(20):
    for j in range(20):
        d = r = d1 = d2 = 0
        if down(i, j):
            d = grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j]
        if right(i, j):
            r = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3]
        if diagonal_1(i, j):
            d1 = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3]
        if diagonal_2(i, j):
            d2 = grid[i][j] * grid[i+1][j-1] * grid[i+2][j-2] * grid[i+3][j-3]
        max_prod = max(max_prod, d, r, d1, d2)

print(max_prod)