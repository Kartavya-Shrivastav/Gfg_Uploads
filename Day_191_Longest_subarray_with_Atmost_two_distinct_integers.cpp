#include <bits/stdc++.h>
using namespace std;

// Problem: Find the length of the longest subarray with at most two distinct integers.
// Approach: Use a sliding window technique with a hash map to keep track of the count of distinct integers.

// Steps:
// 1. Initialize two pointers, i and j, to represent the start and end of the current window.
// 2. Use a map to count the occurrences of each integer in the current window.
// 3. Expand the window by moving j to the right and adding the current integer to the map.
// 4. If the number of distinct integers exceeds two, shrink the window from the left by moving i to the right until there are 
//    at most two distinct integers.
// 5. Keep track of the maximum length of the window during the process.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(1) for the map, as it can only contain at most two distinct integers.


class Solution {
    public:
        // Function to find the length of the longest subarray with at most two distinct integers
        int totalElements(vector<int> &arr) { 
                int ans = 0; // To store the maximum length found
                int i = 0, j = 0; // Window pointers
                map<int, int> mp; // Map to store the count of each integer in the current window
                while (j < arr.size()) {
                        mp[arr[j]]++; // Add current element to the map
                        int c = mp.size(); // Number of distinct integers in the window
                        // If more than 2 distinct integers, shrink window from the left
                        while (c > 2) {
                                mp[arr[i]]--; // Decrease count of the leftmost element
                                if (mp[arr[i]] == 0) {
                                        mp.erase(arr[i]); // Remove element if its count becomes 0
                                        c--; // Decrement the count of distinct integers
                                }
                                i++; // Move left pointer to the right
                        }
                        ans = max(ans, j - i + 1); // Update the maximum length
                        j++; // Expand window to the right
                }
                return ans; // Return the maximum length found
        }
};