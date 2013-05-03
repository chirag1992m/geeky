/* Next power of two - method 3 */
/*
	Right shift a bit of number 1 until it is
	greater than or equal to the number given.

	eg: n = 5
	1 < n
	10 < n
	100 < n
	1000 >= n
	ans = 1000.
*/
/*
	Space complexity = O(1)
	Time Complexity = O(1) // max time = 32 (number of bits)
*/

#include <iostream>

using namespace std;

int findNextPowerofTwo(int n) {
	if(!n)
		return n;
	int i=1;

	while(i < n) {
		i = i<<1;
	}

	return i;
}

int main(int argc, char const *argv[])
{
	int n;
	n=5;
	cout<<findNextPowerofTwo(n)<<endl;
	n=17;
	cout<<findNextPowerofTwo(n)<<endl;
	n=32;
	cout<<findNextPowerofTwo(n)<<endl;
	return 0;
}