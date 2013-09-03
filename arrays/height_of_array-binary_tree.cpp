/*
Given a binary tree in the form of an array where the value at each index is the parent of the index, find the height of the binary tree. 
For example , if arr[i] = j, j is the parent of i. If arr[k] = -1, k is the root.

Write a function which takes in an array and its size as input and returns the height as output. The function signature would be of the following form:
int height(int arr[], int size)

Example 

Assume a binary tree where 2 is the root. 1 is the left child of 2 and 0 is the right child of 2. 
Now the given input array will be of the following form : arr = {2,2,-1} which boils down to the following observation :
arr[0] = 2, 2 is the parent of 0
arr[1] = 2, 2 is the parent of 1
arr[2] = -1, 2 is the root

The output should be 1 which is the height of this binary tree.
*/
#include <iostream>

using namespace std;

int max(int a, int b) {
	if (a>b)
		return a;
	else
		return b;
}

int findHeight(int arr[], int size, int root) {
	int leftchild = -3, rightchild = -3;
	
	if(root == -3)
		return 0;	// BASE-CASE for recurion

	// get the left child
	for(int i=0; i<size; i++) {
		if(arr[i] == root) {
			leftchild = i;
			arr[i] = -2;
			break;
		}
	}

	// get the right child
	for(int i=0; i<size; i++) {
		if(arr[i] == root) {
			rightchild = i;
			arr[i] = -2;
			break;
		}
	}

	return (1 + max(findHeight(arr, size, leftchild), findHeight(arr, size, rightchild)));	// recursive call
}


/* height of array-binary tree - method 1*/
/* This method is based on RECURSION,
	height =  1 + max(height of right subtree, height of left subtree) */
/* Here, first I set the value of height to be 0 and find the root in the binary tree.
	Then search for its children and take the height of the tree as the maximum of
	heights of the sub-trees formed by its children.
	Now, the height of the subtree is found by RECURSION, taking the child as the new root, 
	findHeight is called again for its children. */

/* Space Complexity = O(n)
	Time Complexity = O(n^2)	// searching of children for every element */
int height_1(int arr[], int size) {
	int root, leftchild = -3, rightchild = -3;
	int height = 0;

	// get the root
	for(int i=0; i<size; i++) {
		if(arr[i] == -1) {
			arr[i] = -2;	//as the found array element is no longer required
			root = i;
			break;
		}
	}

	// get the left child
	for(int i=0; i<size; i++) {
		if(arr[i] == root) {
			leftchild = i;
			arr[i] = -2;
			break;
		}
	}

	// get the right child
	for(int i=0; i<size; i++) {
		if(arr[i] == root) {
			rightchild = i;
			arr[i] = -2;
			break;
		}
	}

	return (max(findHeight(arr, size, leftchild), findHeight(arr, size, rightchild)));	// no +1 as root constitute "0" height
}


/* height of array-binary tree - method 2 */
/* Here, for every node I traverse a path to the root,
	as in the array, we have the parent's index 
	Then the path with the maximum length is the height
	of the tree */

/* Space Complexity = O(n)
	Time Complexity = O(n*log(n)) // traversing a path takes log(n) time. */
int height_2(int arr[], int size) {
	int max = 0, height_temp;

	for(int i=0; i<size; i++) {
		height_temp = 0;
		for(int j=i; j != -1; ) {
			j = arr[j];		// going up to the parent (traversing the path from node to root)
			height_temp++;	// height increases every time.
		}

		if(height_temp > max)
			max = height_temp;	// just to find the maximum of all the paths
	}

	return max-1;	// the height is 0 if only root is present
}

int main() {
	int arr[] = {2, 2, -1, 1, 0, 1, 0, 3};

	cout<<height_2(arr, 8)<<endl;		// testing the function - answer should be 3
	cout<<height_1(arr, 8)<<endl;		// testing the function - answer should be 3
}