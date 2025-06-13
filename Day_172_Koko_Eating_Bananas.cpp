#include <bits/stdc++.h>
using namespace std;
// This code is a solution to the Koko Eating Bananas problem.
// The problem is to find the minimum eating speed Koko needs to finish all bananas in k hours.
// The solution uses binary search to find the optimal speed.

class Solution {
    // Helper function to check if Koko can eat all bananas at speed 'mid' within 'k' hours
    bool solve(vector<int>& arr, int mid, int k) {
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            // Add the number of hours needed for each pile at speed 'mid'
            cnt = cnt + (arr[i] / mid);
            // If there are leftover bananas, add one more hour
            if (arr[i] % mid != 0) {
                cnt = cnt + 1;
            }
        }
        // Return true if total hours needed is within 'k'
        return cnt <= k;
    }

public:
    // Main function to find the minimum eating speed
    int kokoEat(vector<int>& arr, int k) {
        int n = arr.size();
        int maxi = INT_MIN;
        // Find the maximum number of bananas in any pile
        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);
        }

        int left = 1;         // Minimum possible speed
        int right = maxi;     // Maximum possible speed
        int ans = 0;          // Store the answer

        // Binary search to find the minimum speed
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If Koko can finish at speed 'mid', try a slower speed
            if (solve(arr, mid, k)) {
                ans = mid;
                right = mid - 1;
            }
            // Otherwise, try a faster speed
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};