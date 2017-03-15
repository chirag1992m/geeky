/*
https://www.hackerrank.com/challenges/30-review-loop
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    
    string str;
    while(N--) {
        cin>>str;
        
        for(int i=0; i<str.size(); i++) {
            if(i%2 == 0)
                cout<<str[i];
        }
        cout<<" ";
        for(int i=0; i<str.size(); i++) {
            if(i%2 == 1)
                cout<<str[i];
        }
        cout<<endl;
    }
    return 0;
}
