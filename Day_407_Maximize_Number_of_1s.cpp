#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary array and an integer k, find the maximum number of consecutive 1s in the array if you can flip at most k 0s.
// Approach: Use a sliding window approach to maintain a window of consecutive 1s and at most k 0s. Expand the window by moving the right pointer and count the number of 0s in the window. If the count exceeds k, move the left pointer to shrink the window until the count of 0s is at most k. Keep track of the maximum length of the window during this process.

// Steps:
// 1. Initialize two pointers, last_zero and current, to keep track of the left boundary of the window and the count of 0s in the current window respectively.
// 2. Iterate through the array with a right pointer. If the current element is 0, increment the current count of 0s.
// 3. If the count of 0s exceeds k, move the left pointer (last_zero) to the right until the count of 0s is at most k. This involves moving last_zero and decrementing current if we encounter a 0.
// 4. Update the answer with the maximum length of the window (right - last_zero + 1) during each iteration.
// 5. After the loop, return the maximum length found.

// Time Complexity: O(n) where n is the size of the array, as we traverse the array once with the right pointer and at most once with the left pointer.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the pointers and counters.

class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int last_zero = 0;
        int current = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(arr[i] == 0)current ++;
            if(current > k){
                while(arr[last_zero] != 0)last_zero ++;
                last_zero++;
                current--;
            }
                ans = max(ans,i-last_zero+1);
        }
        ans = max(ans,n-last_zero);
        return ans;
    }
};