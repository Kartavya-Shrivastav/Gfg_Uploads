#include <bits/stdc++.h>
using namespace std;

// Problem: Longest Bounded Difference Subarray
// Approach: We can use two deques to maintain the maximum and minimum values in the current window.

// Steps:
// 1. Initialize two deques to keep track of the indices of the maximum and minimum elements.
// 2. Use a sliding window approach with two pointers (left and right).
// 3. Expand the right pointer and update the deques accordingly.
// 4. If the difference between the maximum and minimum elements exceeds x, move the left pointer to the right.
// 5. Keep track of the best (longest) subarray found during the process.
// 6. Finally, return the longest subarray found.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
         int n = arr.size();
        deque<int> maxDq, minDq;
        int left = 0, bestStart = 0, bestLen = 0;
    
        for (int right = 0; right < n; right++) {
            while (!maxDq.empty() && arr[maxDq.back()] < arr[right]) 
                maxDq.pop_back();
            maxDq.push_back(right);
    
            while (!minDq.empty() && arr[minDq.back()] > arr[right]) 
                minDq.pop_back();
            minDq.push_back(right);
    
            while (arr[maxDq.front()] - arr[minDq.front()] > x) {
                if (maxDq.front() == left) maxDq.pop_front();
                if (minDq.front() == left) minDq.pop_front();
                left++;
            }
    
            if (right - left + 1 > bestLen) {
                bestLen = right - left + 1;
                bestStart = left;
            }
        }
    
        return vector<int>(arr.begin() + bestStart, arr.begin() + bestStart + bestLen);
    
    }
};