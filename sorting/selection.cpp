/*
	@author: Chirag Maheshwari

	An implementation of selection sort.

	Time - O(n^2)
	Auxiliary space - O(1)
*/
#include <iostream>

using namespace std;

int main() {
	int size, position;
	double arr[100000], minimum;

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* Selection sort starts here */
	for(int i=0; i<size-1; i++) {
		minimum = arr[i];
		position = i;

		for(int j=i+1; j<size; j++) {
			if(arr[j] < minimum) {
				minimum = arr[j];
				position = j;
			}
		}

		arr[position] = arr[i];
		arr[i] = minimum;
	}

	for(int i=0; i<size; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}