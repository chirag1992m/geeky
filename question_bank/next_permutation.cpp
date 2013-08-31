/*
Given a string, find the lexicograhically next permutation.

Eg: 1234 -> 1243 -> 1324 -> 1342 -> 1423 -> 1432 -> 2134 -> 2143 ->..... -> 4321 -> 1234 ->....

thus, given any string in, give the next permutation in the list.
eg: 1342 -> 1423

Algorithm:
scan from the right side, and find the first position where the left element is smaller than it's right neighbour (if no such pair is found, then the current permutation is the last permutation). Now find the successor of the number making the anomaly in its right array.
Swap the number with it's successor.
sort the array right of the number. (this will be as easy as reversing the array, as it is in decreasing order)

@author: Chirag Maheshwari
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool nextPermutation(string &s) {
	int size = s.size(),
		i = size-2;

	for(; i>=0; i--) {
		if(s[i] < s[i+1])
			break;
	}

	char tempChar;
	if(i < 0) {
		/* string is at its last permutation
		reverse the string, that's all. */
		for(int i=0; i<(size/2); i++) {
			tempChar = s[i];
			s[i] = s[size - i - 1];
			s[size - i - 1] = tempChar;
		}

		return false;
	} else {
		/*
			find successor position and swap.

			We will always find a successor, (i+1) is one.
		*/
		int j=size-1;
		for(; true; j--) {
			if(s[j] > s[i])
				break;
		}

		tempChar = s[j];
		s[j] = s[i];
		s[i] = tempChar;

		for(int k=i+1; k<((size - i -1)/2 + i + 1); k++) {
			tempChar = s[k];
			s[k] = s[size - k + i];
			s[size - k + i] = tempChar;
		}

		return true;
	}
}

int main() {
	string s1 = "11345", s2 = "11345";

	while(next_permutation(s2.begin(), s2.end())) {
		nextPermutation(s1);

		cout<<"s1 = "<<s1<<endl<<"s2 = "<<s2<<endl;
		if(s1.compare(s2) != 0) {
			cout<<endl<<"Some anomaly...check"<<endl;
			break;
		}
	}
}