/*
	@author: Chirag Maheshwari

	This is an implementation of heap sort.

	Time - O(n*log(n))
	auxiliary - O(1)
*/
#include <iostream>

using namespace std;

int parentIndex(int child) {
	return ((int)((child - 1)/2));
}

int rightChildIndex(int parent) {
	return 2*parent + 2;
}

int leftChildIndex(int parent) {
	return 2*parent + 1;
}

void heapify(double arr[], int parentIndex, int size) {
	if(parentIndex >= size)
		return;

	int rightPos = rightChildIndex(parentIndex),
		leftPos = leftChildIndex(parentIndex),
		maxPos = parentIndex;

	if(leftPos < size && arr[leftPos] > arr[parentIndex])
		maxPos = leftPos;
	if(rightPos < size && arr[rightPos] > arr[maxPos])
		maxPos = rightPos;

	if(parentIndex != maxPos) {
		double temp = arr[parentIndex];
			arr[parentIndex] = arr[maxPos];
			arr[maxPos] = temp;

		heapify(arr, maxPos, size);
	}
}

void heapSort(double arr[], int size) {
	/* Build the max-heap first */
	int midPoint = (size)/2;

	for(int i=midPoint; i>=0; i--) {
		heapify(arr, i, size);
	}

	/* Now swapping the first element with the last one, */
	for(int i=0; i<size-1; i++) {
		 // swapping the maximum element with the remaining heap size 
		double temp = arr[0];
		arr[0] = arr[size - i - 1];
		arr[size - i - 1] = temp;

		heapify(arr, 0, size - i - 1);
	}
}

int main() {
	int size;
	double arr[100000];
	bool isSorted = true;

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* heap sort starts here */
	heapSort(arr, size);

	for(int i=0; i<size-1; i++) {
		cout<<arr[i]<<"\t";

		if(arr[i] > arr[i+1]) {
			isSorted = false;
		}
	}
	cout<<arr[size-1]<<"\t";
	cout<<"\n";
	if(!isSorted)
		cout<<"NOT SORTED!!!"<<endl;
}