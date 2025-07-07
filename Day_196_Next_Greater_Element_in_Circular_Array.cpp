#include <bits/stdc++.h>
using namespace std;

// Problem: Find the next greater element for each element in a circular array.
// Approach: Use a stack to keep track of indices of elements. Iterate through the array twice to handle the circular nature. 
// For each element, if it is greater than the element at the index stored in the stack, pop from the stack and set the next greater element.

// Steps:
// 1. Initialize a stack to keep track of indices and a result vector initialized with -1.
// 2. Iterate through the array twice (to handle circular nature).  
// 3. For each element, while the stack is not empty and the current element is greater than the element at the index stored 
//    in the stack, pop from the stack and set the next greater element.
// 4. If the current index is less than the size of the array, push it onto the stack.
// 5. Return the result vector containing the next greater elements.

// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(n), for the stack and result vector.

class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int  n = arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=0 ; i<n*2 ; i++){
            while(!st.empty() && arr[st.top()]<arr[i%n]){
                  ans[st.top()] = arr[i%n];
              st.pop();
          }
          if(i<n)
          st.push(i);
      }
      return ans;
            
    }
};

