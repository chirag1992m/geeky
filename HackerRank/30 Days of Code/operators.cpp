/*
https://www.hackerrank.com/challenges/30-operators
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double price, tax, tip;
    cin>>price>>tip>>tax;
    double total = (price) + (price * tip/100) + (price * tax/100);
    cout<<"The total meal cost is "<<(floor(total + 0.5))<<" dollars.";
    return 0;
}