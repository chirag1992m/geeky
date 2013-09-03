/*
	We can multiply a number by 7 using bitwise operator. First left shift the number by 3 bits (you will get 8n) then subtract the original numberfrom the shifted number and return the difference (8n – n).
*/
/*
	Great way to multiply by a multiply by power of 2 is to right shift the bits.

	Thus, to multiply by 7, multiply by 8 (right shift 3 bits.) then subtract the original number.

	Same trick can be applied to fast multiply numbers.

	time complexity - O(1)
	Space complexity - O(1)
*/
#include <iostream>

using namespace std;

int multiplyBySeven(unsigned int num) {
	num = (num << 3) - num;

	return num;
}

int main() {
	int num = 11;

	cout<<multiplyBySeven(num)<<endl;

	return 0;
}