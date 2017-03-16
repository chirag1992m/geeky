'''
Largest Collatz Sequence
https://www.hackerrank.com/contests/projecteuler/challenges/euler014
'''
MAX_COUNT = 5000000

pre_calculated_steps = [-1] * MAX_COUNT
pre_calculated_steps[0] = 0

def get_collatz_steps(n):
    if n <= MAX_COUNT and pre_calculated_steps[n-1] != -1:
        return pre_calculated_steps[n-1]
    
    if n == 1:
        return 0
    
    if n%2 == 0:
        steps = 1 + get_collatz_steps(n//2)
    else:
        steps = 1 + get_collatz_steps(3*n + 1)
        
    if n <= MAX_COUNT:
        pre_calculated_steps[n-1] = steps
    return steps

#Maybe a bottom-up approach can speed this up
#Heat-up the cache
for n in range(1, MAX_COUNT+1):
    get_collatz_steps(n)
    
def get_collatz_steps_cached(n):
    return pre_calculated_steps[n-1]

#This contains the answers
pre_calculated_maxes = [-1] * MAX_COUNT
current_max = 0
current_max_n = 0
for idx, step in enumerate(pre_calculated_steps):
    if current_max <= step:
        current_max = step
        current_max_n = idx+1
    pre_calculated_maxes[idx] = current_max_n

T = int(input().strip())
for t in range(T):
    N = int(input().strip())
    #output the answer from the pre-calculated array
    print(pre_calculated_maxes[N-1])