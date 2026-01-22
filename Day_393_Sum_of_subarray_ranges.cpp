#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of Subarray Ranges
// Given an integer array, find the sum of the ranges of all possible subarrays. For each element, determine how many subarrays it is the maximum and minimum of, and calculate its contribution accordingly.

// Approach: Use monotonic stacks to calculate the contribution of each element as the maximum and minimum in all subarrays.

// Steps:
// 1. Initialize two stacks to help find the next greater and next smaller elements.
// 2. Traverse the array to calculate the total contribution of each element as the maximum in all subarrays.
// 3. Clear the stack and traverse the array again to calculate the total contribution of each element as the minimum in all subarrays.
// 4. The final result is the difference between the total contributions as maximum and minimum.
// 5. Return the result.

// Time Complexity: O(N) where N is the number of elements in the array (each element is pushed and popped at most once).
// Space Complexity: O(N) for the stacks used.

class Solution {
  public:
    int subarrayRanges(vector<int>& arr) {
        stack<int> st;
        int lar_total=0;
        int sma_total=0;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]<arr[i]){
                int num=arr[st.top()];
                int index=st.top();
                st.pop();
                int l_sub=st.empty()?index+1:index-st.top();
                int r_sub=i-index;
                lar_total+=(num*l_sub*r_sub);
            }
            st.push(i);
        }
        while(!st.empty()){
            int num=arr[st.top()];
            int index=st.top();
            st.pop();
            int l_sub=st.empty()?index+1:index-st.top();
            int r_sub=n-index;
                
            lar_total+=(num*l_sub*r_sub);
        }
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&&arr[st.top()]>arr[i]){
                int num=arr[st.top()];
                int index=st.top();
                st.pop();
                int l_sub=st.empty()?index+1:index-st.top();
                int r_sub=i-index;
                
                sma_total+=(num*l_sub*r_sub);
            }
            st.push(i);
        }
        while(!st.empty()){
            int num=arr[st.top()];
            int index=st.top();
            st.pop();
            int l_sub=st.empty()?index+1:index-st.top();
            int r_sub=n-index;
                
            sma_total+=(num*l_sub*r_sub);
        }
        return lar_total-sma_total;
    }
};