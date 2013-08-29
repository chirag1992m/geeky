/*
	@author: Chirag Maheshwari

	This is an implementation of merge sort.

	Time - O(n*log(n))
	auxiliary - O(n) (space sed during merging)
*/
#include <iostream>

using namespace std;

void merge(double arr[], int start, int midPoint, int end) {
	int sizeL = midPoint - start,
		sizeR = end - midPoint,
		size = end - start;

	double arrL[sizeL],
		arrR[sizeR];

	/* populating the left and right arrays to be merge into one */
	for(int i=0; i<sizeL; i++) {
		arrL[i] = arr[start + i];
	}
	for(int i=0; i<sizeR; i++) {
		arrR[i] = arr[midPoint + i];
	}

	int l=0, r=0;
	for(int i=start; i<end; i++) {
		if(l < sizeL && r < sizeR) {
			if(arrL[l] < arrR[r]) {
				arr[i] = arrL[l];
				++l;
			} else {
				arr[i] = arrR[r];
				++r;
			}
		} else if(l < sizeL) {
			arr[i] = arrL[l];
			++l;
		} else {
			arr[i] = arrR[r];
			++r;
		}
	}
}

void mergeSort(double arr[], int start, int end) {
	if((end - start) < 2)
		return;

	int midPoint = ((end - start)/2) + start;

	mergeSort(arr, start, midPoint);
	mergeSort(arr, midPoint, end);

	merge(arr, start, midPoint, end);
}

int main() {
	int size;
	double arr[100000];

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* merge sort starts here */
	mergeSort(arr, 0, size);

	for(int i=0; i<size; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}