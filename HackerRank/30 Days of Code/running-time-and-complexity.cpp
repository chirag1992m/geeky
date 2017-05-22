#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool prime(int num) {
    if(num == 1)
        return false;
    
    int lim = (int)sqrt(num) + 1;
    for(int i=2; i < lim; i++) {
        if(num%i == 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, num;
    cin>>n;
    
    while(n--) {
        cin>>num;
        
        if (prime(num))
            cout<<"Prime"<<endl;
        else
            cout<<"Not prime"<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
