/* Next power of two - method 2 */
/*
	Find the highest bit set to 1.
	set the "highest+1" bit to 1 and all others to 0.
	if the number is itself a power of 2 then return the same number.
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
	int i=1, max = 0, j;
	for(j=1; j<=32; j++) {
		if(i & n)
			max = j;
		i = i<<1;
	}
	max = max-1;
	if(1<<max == n)
		return n;
	else {
		max++;
		return 1<<max;
	}
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