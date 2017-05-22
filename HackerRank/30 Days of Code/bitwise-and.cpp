#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    
    int n, k;
    while(t--) {
        cin>>n>>k;
        if(((k-1)|k) > n && k%2==0)
            cout<<k-2<<endl;
        else
            cout<<k-1<<endl;
    }
    return 0;
}
