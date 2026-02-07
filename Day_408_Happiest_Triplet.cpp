#include <bits/stdc++.h>
using namespace std;

// Problem: Given three arrays a, b, and c, each of size n, find the triplet (a[i], b[j], c[k]) such that the maximum difference between the elements of the triplet is minimized. If there are multiple such triplets, return the one with the smallest sum. The output should be in descending order.
// Approach: Sort the three arrays and use three pointers to traverse them. At each step, calculate the minimum and maximum of the current triplet and update the minimum difference and sum accordingly. Move the pointer that points to the minimum element to try to find a better triplet.

// Steps:
// 1. Sort the three arrays a, b, and c.
// 2. Initialize three pointers i, j, and k to 0, and variables mc (minimum difference) and ms (minimum sum) to INT_MAX.
// 3. While all pointers are within the bounds of their respective arrays, do the following:
//   a. Calculate the minimum and maximum of the current triplet (a[i], b[j], c[k]).
//   b. Calculate the difference (maxi - mini) and the sum (a[i] + b[j] + c[k]) of the current triplet.
//   c. If the difference is less than mc, or if the difference is equal to mc and the sum is less than ms, update mc, ms, and the answer triplet.
//   d. Move the pointer that points to the minimum element among a[i], b[j], and c[k] to try to find a better triplet.
// 4. After the loop, sort the answer triplet in descending order and return it.

// Time Complexity: O(n log n) due to sorting the arrays, and O(n) for the traversal, resulting in O(n log n) overall.
// Space Complexity: O(1) for the pointers and variables, and O(1) for the answer triplet since it always contains three elements.
class Solution {
public:
    vector<int> smallestDiff(vector<int>& a, vector<int>& b, vector<int>& c) {
        int n = a.size();
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        int i = 0, j = 0, k = 0;
        int mc = INT_MAX, ms = INT_MAX;
        vector<int> ans;

        while (i < n && j < n && k < n) {
            int mini = min({a[i], b[j], c[k]});
            int maxi = max({a[i], b[j], c[k]});
            int diff = maxi - mini;
            int sum = a[i] + b[j] + c[k];

            if (diff < mc || (diff == mc && sum < ms)) {
                mc = diff, ms = sum;
                ans = {a[i], b[j], c[k]};
            }

            if (mini == a[i]) i++;
            else if (mini == b[j]) j++;
            else k++;
        }

        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};