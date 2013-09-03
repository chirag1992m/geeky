/*
Next Power of 2
Write a function that, for a given no n, finds a number p which is greater than or equal to n and is a power of 2.

    IP 5
    OP 8     

    IP 17
    OP 32     

    IP 32
    OP 32     
There are plenty of solutions for this. Let us take the example of 17 to explain some of them.
*/

#include <iostream>
#include <cmath>

using namespace std;

/* Next power of two - method 1 */
/* Take the log(base = 2) of the given input and then,
	its ceiling would give the log of the reuired answer.
	Now, finding the power of 2 will be the required answer. */
/*
	space complexity = O(1)
	time complexity = O(log2(n))	// assuming log(n) take a constant amount of time.
*/
int findNextPowerofTwo_1(int n) {
	double temp = (log((double)n))/(log(2.0));
	int ans = ceil(temp);

	return pow(2, ans);
}

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
int findNextPowerofTwo_2(int n) {
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
int findNextPowerofTwo_3(int n) {
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
	cout<<findNextPowerofTwo_1(n)<<endl;
	n=17;
	cout<<findNextPowerofTwo_2(n)<<endl;
	n=32;
	cout<<findNextPowerofTwo_3(n)<<endl;
	return 0;
}