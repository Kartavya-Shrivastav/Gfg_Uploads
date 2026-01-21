#include <bits/stdc++.h>
using namespace std;

// Problem: Stock Span Problem
// Given an array of stock prices, for each day, find the number of consecutive days before it (including the current day)
// where the stock price was less than or equal to the current day's price.

// Approach: Use a stack to keep track of indices of days with stock prices.
// For each day, pop elements from the stack while the price at those indices is less than or equal to the current day's price.
// The span for the current day is the difference between the current index and the index of the top of the stack after popping.

// Steps:
// 1. Initialize an empty stack and push -1 onto it to handle the base case.
// 2. Iterate through each day's stock price.
// 3. For each price, pop from the stack until the top of the stack has a price greater than the current price or the stack is empty.
// 4. The span for the current day is the difference between the current index and the index at the top of the stack.
// 5. Push the current index onto the stack.
// 6. Return the list of spans.

// Time Complexity: O(N) where N is the number of days (each element is pushed and popped at most once).
// Space Complexity: O(N) for the stack and the result array.

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        vector<int> ans;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<arr.size(); i++){
            while(st.top()!=-1 && (arr[st.top()] <= arr[i]))
                st.pop();
            
            ans.push_back(i - st.top());
            st.push(i);
        }
        
        return ans;
    }
};