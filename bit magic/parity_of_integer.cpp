/*
Parity: Parity of a number refers to whether it contains an odd or even number of 1-bits. The number has “odd parity”, if it contains odd number of 1-bits and is “even parity” if it contains even number of 1-bits.
*/

/*
unset the rightmost bit in a loop until the number drops to zero and count.

Unsseting the right-most bit = n & (n-1) // n-1 has the same 1's except the right of right-most bit.

time complexity - O(log(n))
Auxillary space - O(1)
*/
#include <iostream>

using namespace std;

bool getParity(int num) {
	bool parity = true;

	while(num > 0) {
		num = num & (num - 1);	//un-setting the right most bit.

		parity = !parity;
	}

	return parity;
}

int main() {
	int num = 5;

	if(getParity(num))
		cout<<"Even parity"<<endl;
	else
		cout<<"Odd Parity"<<endl;
}