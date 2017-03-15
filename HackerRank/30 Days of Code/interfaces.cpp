/*
https://www.hackerrank.com/challenges/30-interfaces
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class AdvancedArithmetic{
    public:
        virtual int divisorSum(int n)=0;
};

//Write your code here
class Calculator: 
public AdvancedArithmetic {
    public:
        virtual int divisorSum(int n) {
            int sum = 0;
            for(int temp = 1; temp <= n; temp++) {
                if(n%temp == 0)
                    sum += temp;
            }
            return sum;
        }
};

int main(){
    int n;
    cin >> n;
    AdvancedArithmetic *myCalculator = new Calculator(); 
    int sum = myCalculator->divisorSum(n);
    cout << "I implemented: AdvancedArithmetic\n" << sum;
    return 0;
}