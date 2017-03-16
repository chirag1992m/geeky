/*
https://www.hackerrank.com/challenges/30-sorting
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(size_t i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    int totalSwaps = 0;
    for(size_t i=0; i < n; i++) {
        int swaps = 0;
        
        for(size_t j=0; j < n-1; j++) {
            if(arr[j] > arr[j+1]) {
                swaps++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
        totalSwaps += swaps;
        if(swaps == 0)
            break;
    }
    
    cout<<"Array is sorted in "<<totalSwaps<<" swaps."<<endl;
    cout<<"First Element: "<<arr[0]<<endl;
    cout<<"Last Element: "<<arr[arr.size() - 1]<<endl;
    return 0;
}
