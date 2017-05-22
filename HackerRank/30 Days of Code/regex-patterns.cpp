#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    regex e(".+@gmail.com$");
    
    vector<string> s;
    int t;
    cin>>t;
    
    while(t--) {
        string name, email;
        cin>>name>>email;
        if(regex_match(email, e))
            s.push_back(name);
    }
    
    sort(s.begin(), s.end(), less<string>());
    for(auto& i: s)
        cout<<i<<endl;

    return 0;
}
