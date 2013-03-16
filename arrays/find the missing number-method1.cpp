/* method 1 */
/* Here I'll sort the array using turbo sort as the numbers 
are specifically in between 1 to n-1 */
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
	int n, x;
	/* get the value of n */
	cin>>n;

	/* make an array of size n of type boolean */
	bool *arr = new bool[n];
	memset(arr, 0, n);

	for(int i=0; i<n-1; i++) {
		cin>>x;

		/* set the value found to be true in the array */
		arr[x-1] = true;
	}

	for(int i=0; i<n; i++) {
		if(!arr[i]) {
			cout<<i+1<<endl;
			break;
		}
	}

	return 0;
}