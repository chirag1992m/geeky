/*
https://www.hackerrank.com/challenges/30-dictionaries-and-maps
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    unordered_map<string, string> numbers;
    
    string name, number;
    while(N--) {
        cin>>name>>number;
        numbers.insert({name, number});
    }
    
    do {
        cin>>name;
        
        if(!name.empty()) {
            auto it = numbers.find(name);
            if(it != numbers.end())
                cout<<it->first<<"="<<it->second<<endl;
            else
                cout<<"Not found"<<endl;
        }
    } while(!cin.eof());
    
    return 0;
}
