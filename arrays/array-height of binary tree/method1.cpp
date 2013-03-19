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

int height(int arr[], int size) {
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

int main() {
	int arr[] = {2, 2, -1, 1, 0, 1, 0, 3};

	cout<<height(arr, 8)<<endl;		// testing the function - answer should be 3
}