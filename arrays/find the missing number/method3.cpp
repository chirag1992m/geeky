/* find the missing number - method 3 */
/* This method works on the principle of XOR,
	During the input of number, it creates
	two XOR's. One of all the numbers from 1 to n
	and at the same time, of all the inputs. At the end XOR'ing
	the two found XOR's will give us the solution. Here's how it works:
	x = 1^....^n 
	y = 1^...^i^i+2...^n 
	ans = x^y
		= (1^....^n) ^ (1^...^i^i+2...^n)
		= (1^1)^(2^2)....(i^i)^(i+1)^(i+2 ^ i+2)...^(n^n)	// as it is associative and commutative
		= (0)^(0)^.....^(i+1)^...^(0) 
		= (i+1) */

/* Space Complexity = O(1)
	Time Complexity = O(n) */

/*	This method also works around the problem of overflowing
	of the "sum" in the last method */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, x = 0, y = 0, z;
	cin>>n;
	x = n;

	for(int i=0; i<n-1; i++) {
		x = x^(i+1);

		cin>>z;
		y = y^z;
	}
	cout<<(x^y)<<endl;

	return 0;
}