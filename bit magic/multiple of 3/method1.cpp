/* Is a multiple of 3 - method 1 */
/*
	It simply ses the modulo operator to do the
	work.
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int num;
	cout<<"Enter the number: ";
	cin>>num;

	if(num%3 == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}