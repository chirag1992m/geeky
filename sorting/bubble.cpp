/*
	@author: Chirag Maheshwari

	This is an implementation of the bubble sorting algorithm.

	It starts from index 0 and and goes through the array swappig any anomaly found in the array as compared to a sorted array. We do it n-1 times so that the minimum number bubbles to the top (thus the name bubble sort).

	Time complexity - O(n^2)
	Auxiliary space - O(1)
*/
#include <iostream>

using namespace std;

int main() {
	int size;
	double arr[100000], temp;
	bool isSorted = false;

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* Bubble sorting starts from here */
	for(int i=0; i<size-1; i++) {
		isSorted = true;
		for(int j=1; j<size; j++) {
			if(arr[j-1] > arr[j]) {
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;

				isSorted = false;
			}
		}

		if(isSorted)
			break;
	}

	for(int i=0; i<size; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}