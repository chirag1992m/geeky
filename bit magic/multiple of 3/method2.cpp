/* Is a multiple of 3 - method 2 */
/*
	It checks the difference between the odd places bit set 
	and even places bit set. If that is a multiple of 3, then
	the original number is also a multiple of 3.
*/
#include <iostream>

#define INT_BITS 32

using namespace std;

bool isMultipleOf3(int num)
{
	int evenCount = 0,
		oddCount = 0,
		checker = 1;

	if(num < 0)
		num *= -1;
	if (num == 0)
		return true;
	if(num == 1)
		return false;	

	for (int i=0; i<INT_BITS; i++) {
		if(checker & num) {
			if(i%2)
				oddCount++;
			else
				evenCount++;
		}
		checker = checker<<1;
	}

	return isMultipleOf3(oddCount - evenCount);
}

int main(int argc, char const *argv[])
{
	int num;
	cout<<"Enter the number: ";
	cin>>num;

	if(isMultipleOf3(num))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}