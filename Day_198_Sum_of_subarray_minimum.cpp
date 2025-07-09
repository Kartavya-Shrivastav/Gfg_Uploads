#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the sum of the minimums of all subarrays.
// Approach: Use a stack to find the previous and next smaller elements for each element in the array.

// Steps:
// 1. Initialize two vectors to store the indices of the previous and next smaller elements for each element in the array.
// 2. Use a stack to iterate through the array from left to right to find the previous smaller elements.
// 3. Use another stack to iterate through the array from right to left to find the next smaller elements.
// 4. For each element, calculate the contribution of that element to the sum of minimum subarray minimums using the 
//    indices of the previous and next smaller elements.
// 5. Return the total sum.

// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(n), for the stacks and vectors.

class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n=arr.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>st1;
        for(int i=0;i<n;i++){
            while(!st1.empty()&&arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(!st1.empty()){
                left[i]=st1.top();
            }
            st1.push(i);
        }

        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty()&&arr[st2.top()]>arr[i]){
                st2.pop();
            }
            if(!st2.empty()){
                right[i]=st2.top();
            }
            st2.push(i);
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=((i-left[i])*(right[i]-i)*arr[i]);
        }
        
        return ans;
    }
};