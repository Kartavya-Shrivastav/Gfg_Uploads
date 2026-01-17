#include <bits/stdc++.h>
using namespace std;

// Problem: Given a mathematical expression in the form of a string, determine if it contains any redundant brackets. Redundant brackets are those which do not change the meaning of the expression when removed.
// Approach: We can use a stack to keep track of the characters in the expression. When we encounter a closing bracket, we check the top of the stack to see if there are any operators or operands between the matching opening and closing brackets. If there are none, the brackets are redundant.

// Steps:
// 1. Initialize an empty stack.    
// 2. Traverse through each character in the string.
// 3. If the character is an opening bracket or an operand/operator, push it onto the stack.
// 4. If the character is a closing bracket, check the top of the stack:    
//    - If the top is an opening bracket, it means there were no operators/operands between the brackets, hence they are redundant.    
//    - Otherwise, pop elements from the stack until an opening bracket is found, counting the number of elements popped.
// 5. If the count of popped elements is less than or equal to 1, the brackets are redundant.

// Time Complexity: O(N) where N is the length of the string.
// Space Complexity: O(N) for the stack.

class Solution {
  public:
    bool checkRedundancy(string &s) {
        int count=0;
        stack<int>st;
        for(auto it:s){
            if(it=='('){
                st.push(0);
            }
            else if(it==')'){
                if(st.top()<=1)return true;
                st.pop();
            }
            else if(!st.empty()){
                int x=st.top();
                st.pop();
                x++;
                st.push(x);
            }
        }
        return false;
    }
};