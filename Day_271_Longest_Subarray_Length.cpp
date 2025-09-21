#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the length of the longest subarray such that the length of the subarray is greater than or equal to the maximum element in that subarray.
// Approach: Use a stack to keep track of indices of elements in the array. For each element, determine the next greater element and calculate the length of the subarray that can be formed with it as the maximum element.

// Steps:
// 1. Initialize a stack to keep track of indices and a variable to store the maximum length found.
// 2. Iterate through the array, and for each element, determine its next greater element.
// 3. While the stack is not empty and the current element is greater than the element at the index stored at the top of the stack, pop the stack and calculate the length of the subarray that can be formed with the popped element as the maximum.
// 4. Update the maximum length if the calculated length is greater than or equal to the popped element.
// 5. Push the current index onto the stack.
// 6. After processing all elements, return the maximum length found.

// Time Complexity: O(n) where n is the length of the array, as each element is pushed and popped from the stack at most once.
// Space Complexity: O(n) in the worst case for the stack.

class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        int n=arr.size();
         int mxLen=0;
         
         stack<int>st;

         for(int i=0; i<=n; i++){
             int nge=(i==n ? INT_MAX : arr[i]);
             while(!st.empty() && arr[st.top()]<nge){
             int curr=arr[st.top()];
             st.pop();
             
             int len=st.empty() ? i : i-st.top()-1;
             
             if(len>=curr) mxLen=max(mxLen, len);
             }
             st.push(i);
         }
         
         return mxLen;
    }
};