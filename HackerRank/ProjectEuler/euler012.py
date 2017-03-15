#!/bin/python3
'''
Highly Divisible Triangular Number
https://www.hackerrank.com/contests/projecteuler/challenges/euler012
'''
'''
## Pre-processing code.
## Uncomment to get the below array

triangular_numbers = []

MAX_divisor = 1000001

#Sieve of Erastohthenes
prime_temp = [i for i in range(0, MAX_divisor+1)]
primes = []

p = 2
size = len(prime_temp)
while p < size:
    primes.append(prime_temp[p])
    itr = p*2
    while itr < size:
        prime_temp[itr] = -1
        itr += p
    
    p = p+1
    itr = p
    while itr < size:
        if prime_temp[itr] != -1:
            break
        itr = itr+1
    p = itr

#this function can easily be optimized
#by separately taking prime-fctorization
#of n and n+1 and save it for the next 
#call as traingular numbers are generated
#by n(n+1)/2
def get_divisors_num(n):
    divs = 1
    for p in primes:
        temp_divs = 1
        if p > n:
            break
        while n%p == 0:
            n = n//p #Divide by multiplicity
            temp_divs += 1
        divs *= temp_divs
    if n > 1:
        divs *= 2
    return divs

current_num = 0
last_counter = 0
i = 1
while True:
    current_num += i
    divs = get_divisors_num(current_num)
    if get_divisors_num(current_num) > last_counter:
        triangular_numbers.append((divs, current_num))
        last_counter = divs
    if divs > 1000:
        break
    i += 1

print(triangular_numbers)
'''
triangular_numbers = [(1, 1), (2, 3), (4, 6), (6, 28), (9, 36), (16, 120), (18, 300), (20, 528), 
(24, 630), (36, 2016), (40, 3240), (48, 5460), (90, 25200), (112, 73920), (128, 157080), 
(144, 437580), (162, 749700), (168, 1385280), (192, 1493856), (240, 2031120), 
(320, 2162160), (480, 17907120), (576, 76576500), (648, 103672800), (768, 236215980), (1024, 842161320)]

T = int(input().strip())
for t in range(T):
    N = int(input().strip())
    
    for divs in triangular_numbers:
        if divs[0] > N:
            print(divs[1])
            break
