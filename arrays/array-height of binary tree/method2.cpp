/* height of array-binary tree - method 2 */
/* Here, for every node I traverse a path to the root,
	as in the array, we have the parent's index 
	Then the path with the maximum length is the height
	of the tree */

/* Space Complexity = O(n)
	Time Complexity = O(n*log(n)) // traversing a path takes log(n) time. */
#include <iostream>

using namespace std;

int height(int arr[], int size) {
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

int main(int argc, char const *argv[])
{
	int arr[] = {2, 2, -1, 1, 0, 1, 0, 3};

	cout<<height(arr, 8)<<endl;		// testing the function - answer should be 3
	return 0;
}