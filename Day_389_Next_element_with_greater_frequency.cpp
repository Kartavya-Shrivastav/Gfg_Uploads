#include <bits/stdc++.h>    
using namespace std;

// Problem: Given an array, for each element, find the next element to its right that has a greater frequency of occurrence in the array. If no such element exists, return -1 for that position.   
// Approach: We can use a stack to keep track of elements while traversing the array from right to left. We also maintain a frequency map to count occurrences of each element. For each element, we pop elements from the stack until we find one with a greater frequency or the stack becomes empty. If we find such an element, we record it; otherwise, we record -1.

// Steps:
// 1. Create a frequency map to count occurrences of each element in the array.
// 2. Initialize an empty stack and a result array filled with -1.
// 3. Traverse the array from right to left:
//    - While the stack is not empty and the frequency of the top element in the stack
//     is less than or equal to the frequency of the current element, pop the stack.
//    - If the stack is not empty after this, the top element is the next element with a greater frequency; record it in the result array.
//    - Push the current element onto the stack.

// Time Complexity: O(N) where N is the number of elements in the array.    
// Space Complexity: O(N) for the frequency map, stack, and result array.

class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {

        stack<int> st;
        unordered_map<int,int> mp;
        for(int& elem : arr){
            mp[elem]++;
        }
        int n = arr.size();
        vector<int> ans(n,-1);
        for(int i = n-1;i>=0;i--){
            if(!st.empty() &&   mp[arr[i]]<mp[st.top()]){
                ans[i] = st.top();
            }else{
                while(!st.empty() && mp[arr[i]]>=mp[st.top()]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top(); 
                }
            }
            st.push(arr[i]);
        }
        
        return ans;
         
    }
};