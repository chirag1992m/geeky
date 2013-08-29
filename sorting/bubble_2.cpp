/*
	@author: Chirag Maheshwari

	This is another implementation of bubble sort but more optimized.

	As we know, the bigger elements bubble much faster than the smaller elements bubble up, thus we can reduce the size of the array to be sorted now as the maximum element gets in its prescribed place in one pass.

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
	int tempSize = size;
	for(int i=0; i<size-1; i++) {
		isSorted = true;
		for(int j=1; j<tempSize; j++) {
			if(arr[j-1] > arr[j]) {
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;

				isSorted = false;
			}
		}
		if(isSorted)
			break;
					
		tempSize--;
	}

	for(int i=0; i<size; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}
