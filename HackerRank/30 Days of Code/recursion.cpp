/*
https://www.hackerrank.com/challenges/30-recursion
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int N) {
    if(N <= 1)
        return 1;
    else return N * factorial(N-1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    cout<<factorial(N)<<endl;
    return 0;
}
