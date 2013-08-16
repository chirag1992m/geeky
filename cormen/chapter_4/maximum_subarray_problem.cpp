/*
	@author: Chirag Maheshwari

	This program finds the subarray which has the maximum sum of all the sub-arrays. As the output, it gives the starting and ending positions of the maximum subarray in the original array.
*/
/* Method 1 
	This method is the brute force method, and goes though all the possible sub-arrays
	to find the maximum subarray.

	Time - O(n^2)
	Space - O(n) */
/* Method 2 
	This method takes on the philosiphy that if an intermediate sum is greater than or equal to 0, it always icrease the next intermediate sum. Thus, we traverse the array keeping track of the sum seen so far, if it is greater than the maximum sum, then we save it another set of variables. Now if the sum decreases below zero, we reset the sum as this will only have a negative effect on the whole sum (it will happen to help in increasing the sum afterwards, so lets just forget about it.)

	Time - O(n)
	Space - O(n) */
#include <iostream>
#include <utility>

using namespace std;

pair<int, int> maximumSubarrayProblem_method1(int arr[], int size) {
	if(size < 1)
		return pair<int, int>(0, 0);

	int i=0, j=0, sum,
		p=0, q=0, maxSum = arr[0];

	for(; i < size-1; i++) {
		sum = 0;

		for(j = i; j<size; j++) {
			sum = sum + arr[j];
			if(sum > maxSum) {
				p = i;
				q = j;
				maxSum = sum;
			}
		}
	}

	return pair<int, int>(p, q);
}

pair<int, int> maximumSubarrayProblem_method2(int arr[], int size) {
	if(size < 1)
		return pair<int, int>(0, 0);

	int i=0, j=0, sum = 0,
		p=0, q=0, maxSum = arr[0];

	for(; j<size; j++) {
		sum = sum + arr[j];

		if(sum > maxSum) {
			p = i;
			q = j;
			maxSum = sum;
		}
		if(sum < 0) {
			i = j+1;
			sum = 0;
		}
	}

	return pair<int, int>(p, q);
}

int main() {
	int size, arr[100000];
	cout<<"Enter the number of elements in array: ";
	cin>>size;

	cout<<"Enter the elements now: "<<endl;
	for(int i=0; i<size; i++) {
		cin>>arr[i];
	}

	pair<int, int> answer = maximumSubarrayProblem_method1(arr, size);
	cout<<endl<<"Maximum subarray is from "<<answer.first + 1<<" to "<<answer.second + 1<<endl;

	answer = maximumSubarrayProblem_method2(arr, size);
	cout<<endl<<"Maximum subarray is from "<<answer.first + 1<<" to "<<answer.second + 1<<endl;
}