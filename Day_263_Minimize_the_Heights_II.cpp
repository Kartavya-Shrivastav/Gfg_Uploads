#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array representing heights, and a value k, modify each height by either adding or subtracting k to minimize the difference between the maximum and minimum heights.
// Approach: Sort the array and use a greedy approach to find the optimal adjustments for each height.

// Steps:
// 1. Sort the array to easily access the smallest and largest heights.
// 2. Initialize the answer as the difference between the maximum and minimum heights.
// 3. Iterate through the array, considering each height as a potential boundary for the adjusted heights.
// 4. For each height, calculate the potential new minimum and maximum heights after adjustment.
// 5. Update the answer with the minimum difference found during the iterations.

// Time Complexity: O(N log N) due to sorting the array
// Space Complexity: O(1) as we are using a constant amount of space

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
          int n = arr.size();
        if (n == 1) return 0;

        sort(arr.begin(), arr.end());

        int ans = arr[n-1] - arr[0];  // initial difference

        int smallest = arr[0] + k;
        int largest = arr[n-1] - k;

        for (int i = 0; i < n-1; i++) {
            int minH = min(smallest, arr[i+1] - k);
            int maxH = max(largest, arr[i] + k);

            if (minH < 0) continue;  // skip if height becomes negative

            ans = min(ans, maxH - minH);
        }

        return ans;
    }
};