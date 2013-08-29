/*
	@author: Chirag Maheshwari

	This is an implementation of in-place merge sort.

	Time - O(n*log(n))
	auxiliary - O(1)
*/
#include <iostream>

using namespace std;

void inPlaceMerge(double arr[], int start, int midPoint, int end) {
	int l = start,
		r = midPoint,
		size = end - start,
		j;
	double temp;

	while(l <= r && r < end) {
		if(arr[l] <= arr[r]) {
			l++;
		} else {
			temp = arr[r];
			j = r;
			while(j > l) {
				arr[j] = arr[j-1];
				j--;
			}
			arr[l] = temp;
			r++;
			l++;
		}
	}
}

void mergeSort(double arr[], int start, int end) {
	if((end - start) < 2)
		return;

	int midPoint = ((end - start)/2) + start;

	mergeSort(arr, start, midPoint);
	mergeSort(arr, midPoint, end);

	inPlaceMerge(arr, start, midPoint, end);
}

int main() {
	int size;
	double arr[100000];
	bool isSorted = true;

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* merge sort starts here */
	mergeSort(arr, 0, size);

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