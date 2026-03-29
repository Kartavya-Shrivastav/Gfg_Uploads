#include <bits/stdc++.h>
using namespace std;

/*
Problem: Count the number of subarrays where the first element is the minimum.
Approach: We can use a stack to keep track of the indices of the elements in the array. The idea is to maintain a stack of indices such that the elements corresponding to those indices are in increasing order. When we encounter an element that is smaller than the top of the stack, it means that the current element is the minimum for all subarrays that start with the elements corresponding to the indices in the stack.

Steps:
1. Use a stack to keep track of the indices of the elements in the array.
2. Iterate through the array and for each element, pop elements from the stack until the current element is greater than the top of the stack.
3. For each popped element, calculate the number of subarrays that can be formed with that element as the minimum and add it to the count.  
4. After processing all elements, pop any remaining elements from the stack and calculate the number of subarrays for those as well.

Time Complexity: O(n) - Each element is pushed and popped from the stack at most once.
Space Complexity: O(n) - In the worst case, all elements could be in the stack.
*/

class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n = arr.size();
        long long count = 0;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                count += i - st.top();
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            count += n - st.top();
            st.pop();
        }
        
        return count;
    }
};