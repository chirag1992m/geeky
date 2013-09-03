/*
Given a number, find a number which is greater or qual to the given number and forms a palindrome. Give the minimum of all such palindromes.

Eg: 32864 -> 32923
	99999 -> 99999
	10000 -> 10001

First funstion works fine for numbers less than 10000.

Second function works for numbers having greater than 5 digits.

Third implementation is an optimized algorithm for the second implementation.

Algorithm:
Make a copy of the given number so that we can compare our constructed palindrome with the original one, if it is greater than or not.
All the changes are done in the copy and the copy is compared with the original until it is greater than the original one.

Firstly, we make a mirror image so that we find the closest palindrome to the given number (smaller or greater or maybe equal too.) eg: 31265547 -> 31266213
now we check if the new palindrome is greater than the original number or not, we start by increasing the middle digit(if even number of digits, then increasing both of them) until the palindrome is greater than the original number. if the middle number is qual to 9, then we make that digit 0 and carry a 1 to the left, and doing this until we find a larger number than the original number. Every time we preserve the "mirror" as if we change one digit on the left, we change the corresponding digit on the right.

@Author: Chirag Maheshwari
*/
#include <iostream>
#include <string>

using namespace std;

int str2num(string s) {
	int num = 0;
	for(int i=0; i<s.size(); i++) {
		num = (num*10) + (s[i] - '0');
	}

	return num;
}

int reverseNumber(int n) {
	int rev = 0;
	while(n>0) {
		rev = (rev*10) + (n%10);
		n /= 10;
	}

	return rev;
}

int nextPalindromeSmall(string s) {
	int num = str2num(s);

	do {
		++num;
	} while(num != reverseNumber(num));

	return num;
}

string nextPalindromeBig(string s) {
	string ss = s;
	int size = ss.size(),
		midPoint1, midPoint2;

	for(int i=0; i<(ss.size()/2); i++) {
		ss[size - i -1] = ss[i];
	}

	if(ss <= s) {

		if(size%2 == 0) {
			midPoint2 = size/2;
			midPoint1 = midPoint2 - 1;
		} else {
			midPoint1 = midPoint2 = size/2;
		}

		bool carry = false;

		for(int i=midPoint1; i>=0;) {
			if(ss[i] != '9' && carry) {
				ss[i]++;
				ss[size - i - 1] = ss[i];
				carry = false;
			} else if(carry) {
				ss[size - i - 1] = ss[i] = '0';
				i--;
			} else if(ss[i] != '9') {
				ss[i]++;
				ss[size - i - 1] = ss[i];
			} else {
				ss[i] = '0';
				ss[size - i - 1] = ss[i];
				i--;
				carry = true;
			}

			if(!carry && s.compare(ss) < 0)
				break;
		}

		if(carry) {
			ss = '1' + ss;
			ss[ss.size() - 1] = ss[0];
		}
	}

	return ss;
}

/* Optimized algo for the above one */
string nextPalindromeBig_2(string ss) {
	string s = ss;
    int inc, dec;
    inc = s.size()/2;
    dec = inc;
    if(s.size()%2==0)
        dec--;
    for(int i=inc,j=dec;i<s.size() && j>=0;i++,j--)
        s[i]=s[j];
    while(s.size()<=ss.size() && s<=ss)
    {
        int i=dec, j=inc;
        while((s[i]-'0')==9 && i>=0 && j<s.size())
        {
            s[i] = s[j] = '0';
            i--;
            j++;
        }
        if(i<0)
        {
            s = "1"+s;
            int l = s[s.size()-1]-'0';
            l++;
            s[s.size()-1] = (l+'0');
        }
        else
        {
            int l = s[i]-'0';
            l++;
            s[i]=s[j]=(l+'0');
        }
    }

    return s;
}

int main() {
	ios::sync_with_stdio(false);

	int T;
	string num;

	cin>>T;
	while(T--) {
		cin>>num;

		/* Uncomment for numbers smaller than 10000 */
		// cout<<nextPalindromeSmall(num)<<'\n';

		/* Use for numbers having more than 5 digits */
		cout<<nextPalindromeBig(num)<<'\n';

		/* Using the more optimized algorithm */
		cout<<nextPalindromeBig_2(num)<<'\n';
	}
}