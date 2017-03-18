'''
Maximum path sum I
https://www.hackerrank.com/contests/projecteuler/challenges/euler018
'''

'''
This is a basic DP problem.
Traverse the triangle from top to bottom
and save the number current maximum sum
till that row
Return the maximum from the last row

I guess, we can also do a bottom to top
approach and the maximum will stored at the top 
of the triangle.
'''
def get_max_path_sum(triangle, rows):
    for row in range(1, rows):
        triangle[row][0] += triangle[row-1][0]
        for i in range(1, row):
            triangle[row][i] += max(triangle[row-1][i], triangle[row-1][i-1])
        triangle[row][row] += triangle[row-1][row-1]
    return max(triangle[rows-1])

T = int(input().strip())
for t in range(T):
    N = int(input().strip())
    
    triangle = []
    for n in range(N):
        nums = input().strip().split()
        triangle.append([int(num) for num in nums])
    
    print(get_max_path_sum(triangle, N))