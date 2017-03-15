/*
https://www.hackerrank.com/challenges/30-binary-numbers
*/
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    int max1s = 0, current = 0;
    while(n > 0) {
        current = current * (n%2) + (n%2);
        
        if(current > max1s)
            max1s = current;
        
        n /= 2;
    }
    
    cout<<max1s;
    return 0;
}
