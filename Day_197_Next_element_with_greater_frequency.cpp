#include <bits/stdc++.h>
using namespace std;

// Problem: Find the next greater element for each element based on frequency in the array.
// Approach: Use a stack to keep track of indices and their frequencies. Iterate through the array and for each element, if it has a 
//           greater frequency than the element at the index stored in the stack, pop from the stack and set the next greater element
//           based on frequency.

// Steps:
// 1. Count the frequency of each element in the array using a map.
// 2. Initialize a stack to keep track of indices and their frequencies.
// 3. Iterate through the array. For each element, while the stack is not empty and the current element's frequency
//    is greater than the frequency of the element at the index stored in the stack, pop from the stack and set the next
//    greater element based on frequency.
// 4. Push the current index and its frequency onto the stack.
// 5. Return the result vector containing the next greater elements based on frequency.

// Time Complexity: O(n), where n is the size of the array.
// Space Complexity: O(n), for the stack and result vector.

class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        map<int,int>mp;
        for(int i:arr){
            mp[i]++;
        }
        
        vector<int>ans(arr.size(),-1);
        stack<pair<int,int>>st;
        
        for(int i=0;i<arr.size();i++){
            if(st.empty()){
                st.push({i,mp[arr[i]]});
            }
            else{
                while(!st.empty()&&arr[i]!=arr[st.top().first] && mp[arr[i]] > st.top().second){
                    ans[st.top().first]=arr[i];
                    st.pop();
                }
                
                st.push({i,mp[arr[i]]});
            }
        }
        
        return ans;
    }
};