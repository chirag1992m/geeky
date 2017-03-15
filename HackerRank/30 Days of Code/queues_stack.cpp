/*
https://www.hackerrank.com/challenges/30-queues-stacks
*/

#include <iostream>

using namespace std;

class Solution {
    //Write your code here
    char queue[100];
    int start, end;
    
    char stack[100];
    int top;

    public:
    Solution() {
        start = end = top = -1;
    }
    
    void pushCharacter(char s) {
        if(top == 99) {
            return;
        }
        
        top++;
        stack[top] = s;
    }
    
    char popCharacter() {
        if(top < 0) {
            return '\0';
        }
        
        char toReturn = stack[top];
        top--;
        
        return toReturn;
    }
    
    void enqueueCharacter(char s) {
        if(start == end && start == -1) {
            start = end = 0;
            queue[end] = s;
        } else if (start == end + 1 || (start == 0 && end == 99)) {
            return; //Queue filled
        } else {
            end = (end + 1)%100;
            queue[end] = s;
        }
    }
    
    char dequeueCharacter() {
        if(start == end && start == -1) {
            return '\0'; //Empty Queue
        }
        char toReturn = queue[start];
        
        start = (start+1)%100;
        if(start == end) {
            queue[0] = queue[start];
            start = end = 0;
        }
        
        return toReturn;
    }
};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}