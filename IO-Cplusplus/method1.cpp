/*
	method 1 - simple cin/cout
*/
/*
	extract from cplusplus.com
	Note: Cin is notorious at causing input issues because it doesn't remove the newline character from the stream or do type-checking. So anyone using cin>>var; and following it up with another cin>>stringtype; or getline(); will receive empty inputs. It's best practice to NOT MIX the different types of input methods from cin.
*/
#include <iostream>
#include <string>

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
}