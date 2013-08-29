/*
	@author: Chirag Maheshwari

	This program calculates the number of inversions in an array.
	Let A[1...n] be an array of n distinct numbers. If i < j and A[i] > A[j], then tha pair(i, j) is called an inversion.
*/

/* Method 1
	This is the brute force method to calculate the inversions.
	For every member of the array, travereses its right part of the array and finds the number of inversions.

	Time Complexity - O(n^2)
	Space Complexity - O(n) */
/* Method 2
	This uses the Divide and conquer methodology by modifying the merge sort to calculate the inversions.
	When the two parts of the array are merged, for every insertion in the main array from the right part, we add the number of remaining elements in the left array to the count of inversions.

	Time complexity - O(n*log(n))
	Space complexity - O(n) */

#include <iostream>

using namespace std;

int countInversion_method1(int arr[], int size) {
	int inversionCount = 0;

	for(int i=0; i<size; i++) {
		for(int j=i+1; j<size; j++) {
			if(arr[i] > arr[j])
				inversionCount++;
		}
	}

	return inversionCount;
}

int countInversion_method2(int arr[], int start, int end) {
	/* Base value case */
	if((end - start) < 2)
		return 0;

	int midPoint = ((end-start)/2) + start;
	int countFromfirstPart = 0, countFromSecondPart = 0, totalCount = 0;

	/* Dividing the array in two parts and recursively counting the inverions on every part */
	countFromfirstPart = countInversion_method2(arr, start, midPoint);
	countFromSecondPart = countInversion_method2(arr, midPoint, end);

	/* Merging the two arrays here */
		/* First copy the parts of array in a temporary array */
	int sizeL = (midPoint - start),
		sizeR = (end - midPoint),
		arrL[sizeL],
		arrR[sizeR],
		size = end - start;

	for(int i=0; i<sizeL; i++) {
		arrL[i] = arr[start + i];
	}
	for(int i=0; i<sizeR; i++) {
		arrR[i] = arr[midPoint + i];
	}

	int l=0, r=0;
	for(int i=start; i<start + size; i++) {
		if(l < sizeL && r < sizeR) {
			if(arrL[l] <= arrR[r]) {
				arr[i] = arrL[l];
				l++;
			} else {
				arr[i] = arrR[r];
				r++;
				totalCount = totalCount + (sizeL - l);
			}
		} else if(l < sizeL) {
			arr[i] = arrL[l];
			l++;
		} else {
			arr[i] = arrR[r];
			r++;
		}
	}

	totalCount = totalCount + countFromfirstPart + countFromSecondPart;

	return totalCount;
}

int main() {
	int size, arr[100000];

	cout<<"Enter the number of elements in array: ";
	cin>>size;
	cout<<"Enter the elements now: "<<endl;

	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	cout<<"From brute force method: "<<countInversion_method1(arr, size)<<endl;
	cout<<"From divide-and-conquer paradigm (extending merge sort): "<<countInversion_method2(arr, 0, size)<<endl;

	return 0;
}