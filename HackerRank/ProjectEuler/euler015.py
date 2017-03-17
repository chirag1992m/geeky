'''
Lattice Paths
https://www.hackerrank.com/contests/projecteuler/challenges/euler015
'''

'''
Dynamic memoization of the recursive solution
that number of steps to point (x, y)
is the same as steps to (x-1, y) and (x, y-1)
as we can move down or right only. Thus, one can come from
left or up only.
'''
modulo = 1000000007
N, M = 500, 500
DP_arr = [[0] * (M+2) for i in range(N+2)]

for i in range(1, N+2):
    for j in range(1, M+2):
        DP_arr[i][j] = (DP_arr[i-1][j] + DP_arr[i][j-1])%modulo
        if i==1 and j==1:
            DP_arr[i][j] = 1
  
T = int(input().strip())
for t in range(T):
    n, m = input().strip().split()
    n, m = int(n), int(m)
    print(DP_arr[n+1][m+1])