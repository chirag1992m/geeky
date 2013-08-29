/*
	@author: Chirag Maheshwari

	This is a simple implementation of quick sort.

	Time(average/best) - O(n*log(n))
	Time(worst) - O(n^2)

	auxiliary space(average) - O(n)
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
		sizeL = 0,
		sizeR = 0;
	double arrL[end-start],
			arrR[end-start],
			pivot = arr[midPoint];

	for(int i=start; i<end; i++) {
		if(i != midPoint) {
			if(arr[i] < pivot) {
				arrL[sizeL] = arr[i];
				sizeL++;
			} else {
				arrR[sizeR] = arr[i];
				sizeR++;
			}
		}
	}

	/* recursively calling quicksort on the partitioned parts */
	quickSort(arrL, 0, sizeL);
	quickSort(arrR, 0, sizeR);

	/* concatenating the two lists back into one array */
	int i=start, j=0;
	for(; j<sizeL; j++) {
		arr[i] = arrL[j];
		i++;
	}
	arr[i] = pivot;
	i++;
	for(j=0; j<sizeR; j++) {
		arr[i] = arrR[j];
		i++;	
	}
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