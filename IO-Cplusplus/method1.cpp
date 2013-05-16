/*
	method 1 - simple cin/cout

	Should not be used for peformance intensive IO
*/
/*
	extract from cplusplus.com
	Note: Cin is notorious at causing input issues because it doesn't remove the newline character from the stream or do type-checking. So anyone using cin>>var; and following it up with another cin>>stringtype; or getline(); will receive empty inputs. It's best practice to NOT MIX the different types of input methods from cin.
*/
/*
	I am a little confused if cin/cout are buffered or unbuffered.
	As far as I know, they are unbuffered. But stream I/O is buffered, so they
	are contradicting statements. (endl is generally used to flush a buffer. This
	is also in the favor of cin/cout being buffered).
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	/* integer or any integer like */
	int integer;
		cin>>integer;
		cout<<integer<<endl;

	/* character string */
	char charstring[100];
		cin>>charstring;	// stops input after a "space"
		cout<<charstring<<endl;

		cin.getline(charstring, 100);	// stops after 100 character or eof whichever comes first
		cout<<charstring<<endl;

	string strstring;
		cin>>strstring;		// stops input after a "space"
		cout<<strstring<<endl;

		getline(cin, strstring);	// stops after eof or '\n', whichever comes first
		cout<<strstring<<endl;

	/* safest way to get an integer (but very slow) - taken from cpluspls.com */
	int number = 0;
	string input;
	while(true) {
		getline(cin, input);

		stringstream myStream(input);
		if(myStream>>number)
			break;
	}


	/* Safest way to get a single character */
	char singlechar = {0};
	while(true) {
		getline(cin, input);

		if(input.length() == 1){
			singlechar = input[0];
			break;
		}
	}
}
