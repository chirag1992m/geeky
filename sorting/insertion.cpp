/*
	@author: Chirag Maheshwari

	This is an implementation of insertion sort.

	Time(worst case/average case) - O(n^2)
	Auxiliary space - O(1)
*/
#include <iostream>

using namespace std;

int main() {
	int size;
	double arr[100000], key;

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* Insertion sort starts here */
	for(int i=1; i<size; i++) {
		key = arr[i];

		for(int j=i-1; j>=0; j--) {
			if(arr[j] > key) {
				arr[j+1] = arr[j];
				arr[j] = key;
			} else
				break;
		}
	}

	for(int i=0; i<size; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}