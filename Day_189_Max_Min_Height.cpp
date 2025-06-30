#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize the minimum height of plants after at most k water additions
// Approach: Use binary search to find the maximum possible minimum height after watering the plants.

// Helper function to check if it's possible to achieve a minimum height t with k water additions
// and a watering range of w.

// Steps:
// 1. Initialize a difference array to track water additions.
// 2. Iterate through each plant and calculate the current height after applying water.
// 3. If the current height is less than t, calculate the water needed to reach t.
// 4. Update the total water used and check if it exceeds k.
// 5. If it does not exceed k, apply the water and mark the range in the difference array.
// 6. Return true if all plants can reach height t, otherwise return false.

// Time Complexity: O(n log(maxHeight)), where n is the number of plants and maxHeight is the maximum possible height after watering.
// Space Complexity: O(n) for the difference array.


bool check(int t, int n, int k, int w, vector<int>& arr) {
    int currWater = 0; // Tracks the current water added at position i
    int dayUsed = 0;   // Total water used so far
    vector<int> water(n + 1, 0); // Difference array to efficiently apply water

    for (int i = 0; i < n; i++) {
        currWater += water[i]; // Update current water at position i
        int currHeight = arr[i] + currWater; // Current height after water
        if (currHeight < t) {
            int need = t - currHeight; // Water needed to reach height t
            dayUsed += need;           // Add to total water used
            if (dayUsed > k) return false; // Exceeded allowed water
            currWater += need;         // Apply water at current position
            water[i] += need;          // Mark start of water addition
            if (i + w <= n) {
                water[i + w] -= need;  // Mark end of water effect
            }
        }
    }

    return true; // Possible to achieve height t for all
}

// Main function to find the maximum possible minimum height after at most k water additions
int maxMinHeight(vector<int> &arr, int k, int w) {
    int n = arr.size();
    int lo = *min_element(arr.begin(), arr.end()); // Minimum initial height
    int hi = lo + k; // Maximum possible minimum height

    // Binary search for the answer
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, n, k, w, arr)) {
            lo = mid + 1; // Try for a higher minimum height
        } else {
            hi = mid - 1; // Lower the minimum height
        }
    }
    return hi; // Maximum minimum height achievable
}