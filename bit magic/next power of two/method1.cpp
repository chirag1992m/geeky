/* Next power of two - method 1 */
/* Take the log(base = 2) of the given input and then,
	its ceiling would give the log of the reuired answer.
	Now, finding the power of 2 will be the required answer. */
/*
	space complexity = O(1)
	time complexity = O(1)	// assuming log(n) take a constant amount of time.
*/

#include <iostream>
#include <cmath>

using namespace std;

int findNextPowerofTwo(int n) {
	double temp = (log((double)n))/(log(2.0));
	int ans = ceil(temp);

	return pow(2, ans);
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