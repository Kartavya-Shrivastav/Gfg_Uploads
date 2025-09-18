#include <bits/stdc++.h>
using namespace std;

// Problem: Given a circular array, find the next greater element for each element in the array.
// Approach: Use a stack to keep track of the next greater elements while iterating through the array twice.

// Steps:
// 1. Initialize a stack to keep track of the next greater elements.
// 2. Iterate through the array twice (to simulate the circular nature).
// 3. For each element, pop elements from the stack until the top of the stack is greater than the current element or the stack is empty.
// 4. If the stack is not empty, the top of the stack is the next greater element for the current element.
// 5. Push the current element onto the stack.

// Time Complexity: O(n) where n is the number of elements in the array.
// Space Complexity: O(n) for the stack and the result array.

class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
          int n=arr.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            while(!st.empty()  && st.top()<=arr[i%n]){
                st.pop();
            }
            
            if( !st.empty() && i<n){
                ans[i]=st.top();
            }
            
            st.push(arr[i%n]);
        }
        
        return ans;
    }
};