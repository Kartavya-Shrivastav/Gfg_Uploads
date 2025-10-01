#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum subarray sum 2
// Approach: We can use a deque to maintain the minimum prefix sums within the given bounds [a, b].

// Steps:
// 1. Calculate the prefix sums of the array.
// 2. Use a deque to keep track of the indices of the prefix sums that are within the bounds [a, b].
// 3. For each prefix sum at index i, remove indices from the front of the deque that are out of the range [i-b, i-a].
// 4. Remove indices from the back of the deque while the prefix sum at those indices is greater than the current prefix sum at index i-a.
// 5. Add the current index i-a to the deque.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
         int n = arr.size();
        int ans = INT_MIN;
        deque <int> q;
        
        vector <int> pre(n+1, 0);
        for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + arr[i-1];
        
        for(int i = a; i <= n; i++){
            while(!q.empty() && q.front() + b < i) q.pop_front();
            while(!q.empty() && pre[q.back()] > pre[i-a]) q.pop_back();
            q.push_back(i-a);
            
            ans = max(ans, pre[i] - pre[q.front()]);
        }
        
        return ans;
    }
};