/*
	@author: Chirag Maheshwari

	This is a simple implementation of in-place quick sort.

	Time(average/best) - O(n*log(n))
	Time(worst) - O(n^2)

	auxiliary space(average) - O(log(n)) space used by the recursive calls
*/
#include <iostream>

using namespace std;

void swap(double &a, double &b) {
	double temp = a;
	a = b;
	b = temp;
}

void quickSort(double arr[], int start, int end) {
	if((end - start) < 2)
		return;

	/* Partitioning the array into two parts satisfying the quick sort condition */
	int midPoint = ((end - start)/2) + start,
		pos = start;
	double pivot = arr[midPoint],
		temp;

	swap(arr[midPoint], arr[end-1]);
	for(int i=start; i<end-1; i++) {
		if(arr[i] < pivot) {
			swap(arr[i], arr[pos]);

			++pos;
		}
	}
	swap(arr[pos], arr[end-1]);

	/* recursively calling quicksort on the partitioned parts */
	quickSort(arr, start, pos);
	quickSort(arr, pos, end);
}

int main() {
	int size;
	double arr[100000];

	cin>>size;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	/* quick sort starts here */
	quickSort(arr, 0, size);

	for(int i=0; i<size; i++) {
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";

}