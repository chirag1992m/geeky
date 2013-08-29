/*
Insertion Sort Advanced Analysis
Insertion Sort is a simple sorting technique which was covered in previous challenges. In the running time challenge, we directly counted how many shifts (or swaps) it takes for insertion sort to finish sorting an array. However, some arrays may be too large for us to wait around for insertion sort to finish. Is there some other way we can calculate the number of times Insertion Sort shifts over elements when sorting an array?

Input:
The first line contains the number of test cases T. T test cases follow. The first line for each case contains N, the number of elements to be sorted. The next line contains N integers a[1],a[2]…,a[N].

Output:
Output T lines, containing the required answer for each test case.

Constraints:
1 <= T <= 5
1 <= N <= 100000
1 <= a[i] <= 1000000

Sample Input:
2
5
1 1 1 2 2
5
2 1 3 1 2

Sample Output:
0
4
*/
#include <iostream>

using namespace std;

long long int countInversions(int arr[], int start, int end) {
	if((end - start) < 2)
		return 0;

	int midPoint = ((end - start)/2) + start;
	long long int count_inversion_1 = 0,
		count_inversion_2 = 0,
		mergeInversions = 0;

	count_inversion_1 = countInversions(arr, start, midPoint);
	count_inversion_2 = countInversions(arr, midPoint, end);

	int sizeL = midPoint - start,
		sizeR = end - midPoint,
		arrL[sizeL],
		arrR[sizeR],
		size = end-start,
		r = 0, l = 0;

	for(int i=0; i<sizeL; i++)
		arrL[i] = arr[start + i];
	for(int i=0; i<sizeR; i++)
		arrR[i] = arr[midPoint + i];

	for(int i=0; i<size; i++) {
		if(l < sizeL && r < sizeR) {
			if(arrL[l] <= arrR[r]) {
				arr[start + i] = arrL[l];
				l++;
			} else {
				arr[start + i] = arrR[r];
				mergeInversions += sizeL - l;
				r++;
			}
		} else if(l < sizeL) {
			arr[start + i] = arrL[l];
			l++;
		} else {
			arr[start + i] = arrR[r];
			r++;
		}
	}

	mergeInversions += count_inversion_2 + count_inversion_1;
	return mergeInversions;
}

int main() {
	int T,
		size,
		arr[100002];

	cin>>T;
	
	while(T--) {
		cin>>size;

		for(int i=0; i<size; i++) {
			cin>>arr[i];
		}

		cout<<countInversions(arr, 0, size)<<endl;
	}

	return 0;
}