/*
QuickSort
In the previous challenge, you wrote a partition method to split an array into smaller and greater elements. This means you ‘sorted’ half the array with respect to the other half. Can you repeatedly use partition to sort an entire array?

Guideline
In Insertion Sort, you simply went through each element in order and inserted it into a sorted sub-array. In this challenge, you cannot focus on one element at a time, but instead must deal with whole sub-arrays, with a strategy known as “divide and conquer”.

When partition is called on an array, two parts of the array get ‘sorted’ with respect to each other. If partition is then called on each sub-array, the array will now be split into 4 parts, each part consisting of smaller numbers than the part to the right. This process could be repeated until the sub-arrays are small. Notice that when partition is called on just two numbers, they end up being sorted.

Can you repeatedly call partition so that the entire array ends up sorted?

Print Sub-Arrays
In this challenge, print your array every time your partitioning method finished, i.e. print every sorted sub-array The first element in a sub-array should be used as a pivot. Partition the left side before partitioning the right side. The pivot should not be added to either side. Instead, put it back in the middle when combining the sub-arrays together.

Input Format
There will be two lines of input:

n - the size of the array
ar - the n numbers of the array
Output Format
Print every partitioned sub-array on a new line.

Constraints
1<=n<=1000 
-1000<=x<= 1000 , x ∈ ar
There are no duplicate numbers.

Sample Input

7
5 8 1 3 7 9 2

Sample Output
2 3 
1 2 3 
7 8 9 
1 2 3 5 7 8 9

Explanation
This is a diagram of QuickSort operating on the sample array:

quick-sort diagram

Task
The method quickSort takes in one parameter: ar, an unsorted array. Use a QuickSort Algorithm to sort the entire array.
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */
void quickSort(vector <int>  &ar) {
    if(ar.size() < 2)
        return;
    int key = ar[0],
        size = ar.size();
    
    vector<int> arrL, arrR;
    
    for(int i=1; i<size; i++) {
        if(ar[i] < key) {
            arrL.push_back(ar[i]);
        } else {
            arrR.push_back(ar[i]);
        }
    }
    
    quickSort(arrL);
    quickSort(arrR);
    
    int j = 0;
    for(int i=0; i<arrL.size(); i++, j++)
        ar[j] = arrL[i];
    ar[j] = key;
    j++;
    for(int i=0; i<arrR.size(); i++, j++)
        ar[j] = arrR[i];
    
    for(int i=0; i<ar.size(); i++)
        cout<<ar[i]<<" ";
    cout<<endl;
}
/* Tail starts here */
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp);
}

quickSort(_ar);
   
   return 0;
}