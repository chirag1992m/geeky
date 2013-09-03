/*
Find the Missing Number
June 22, 2009
You are given a list of n-1 integers and these integers are in the range of 1 to n. There are no duplicates in list. One of the integers is missing in the list. Write an efficient code to find the missing integer.

Example:
I/P    [1, 2, 4, ,6, 3, 7, 8]
O/P    5
*/

#include <iostream>
#include <cstring>

using namespace std;

/* find the missing number - method 1 */
/* Here I'll sort the array using turbo sort as the numbers 
are specifically in between 1 to n-1 and then check the 
final array for the missing number. */

/* Space Complexity = O(n)
	time Complexity = O(n) */
int findMissingNumber_1(int nums[], int size) {
	/* make an array of size n of type boolean */
	bool *arr = new bool[size+1];
	memset(arr, 0, size+1);

	for(int i=0; i<size; i++) {
		/* set the value found to be true in the array */
		arr[nums[i] - 1] = true;
	}

	for(int i=0; i<size+1; i++) {
		if(!arr[i]) {
			return i+1;
		}
	}

	return -1;
}

/* find the missing number - method 2 */
/* We find the sum of numbers 1 to n using the formula n(n+1)/2 
	then as we subtract every number we get from the above 
	found sum, we will be left with the missing number as
	the final product. */
/* Space Complexity = O(1)
	time Complexity = O(n) */
/* This method decreases the space complexity from the
	previous method */
int findMissingNumber_2(int nums[], int size) {
	int n = size+1;
	long long sum = ((n * (n+1)) / 2);

	for(int i=0; i< size; i++) {
		sum -= nums[i];
	}

	return sum;
}

/* find the missing number - method 3 */
/* This method works on the principle of XOR,
	During the input of number, it creates
	two XOR's. One of all the numbers from 1 to n
	and at the same time, of all the inputs. At the end XOR'ing
	the two found XOR's will give us the solution. Here's how it works:
	x = 1^....^n 
	y = 1^...^i^i+2...^n 
	ans = x^y
		= (1^....^n) ^ (1^...^i^i+2...^n)
		= (1^1)^(2^2)....(i^i)^(i+1)^(i+2 ^ i+2)...^(n^n)	// as it is associative and commutative
		= (0)^(0)^.....^(i+1)^...^(0) 
		= (i+1) */

/* Space Complexity = O(1)
	Time Complexity = O(n) */

/*	This method also works around the problem of overflowing
	of the "sum" in the last method */
int findMissingNumber_3(int nums[], int size) {
	int x = size+1, y = 0;

	for(int i=0; i< size; i++) {
		x = x ^ (i+1);

		y = y ^ (nums[i]);
	}

	return (x^y);
}

int main(int argc, char const *argv[]) {
	int n, x, arr[10000];
	/* get the value of n */
	cin>>n;

	for(int i=0; i<n-1; i++) {
		cin>>arr[i];
	}

	cout<<findMissingNumber_1(arr, n-1)<<endl;
	cout<<findMissingNumber_2(arr, n-1)<<endl;
	cout<<findMissingNumber_3(arr, n-1)<<endl;

	return 0;
}