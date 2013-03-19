/* find the missing number - method 2 */
/* We find the sum of numbers 1 to n using the formula n(n+1)/2 
	then as we subtract every number we get from the above 
	found sum, we will be left with the missing number as
	the final product. */
/* Space Complexity = O(1)
	time Complexity = O(n) */
/* This method decreases the space complexity from the
	previous method */

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, x;
	long long sum;	/* as the sum will be much larger than the value of n itself */ 

	cin>>n;
	sum = (n * (n+1)) / 2;

	for(int i=0; i< n-1; i++) {
		cin>>x;
		sum -= x;
	}

	cout<<sum<<endl;

	return 0;
}