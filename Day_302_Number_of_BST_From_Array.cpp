#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of unique integers, for each element, find the number of distinct BSTs that can be formed with that element as the root.
// Approach: Use Catalan numbers to compute the number of distinct BSTs for left and right subtrees.

// Steps:
// 1. Precompute Catalan numbers up to the size of the array.
// 2. For each element in the array, determine how many elements are smaller (left subtree) and how many are larger (right subtree).
// 3. The number of distinct BSTs with that element as root is the product of the Catalan numbers of the left and right subtree sizes.  
// 4. Store the results in an answer array and return it.

// Time Complexity: O(n^2) due to the nested loop for Catalan number computation.
// Space Complexity: O(n) for storing Catalan numbers and the answer array.

class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
       int n = arr.size();
        vector<int> ans;
        vector<int> vec = arr;
        sort(vec.begin(), vec.end());

        // Precompute Catalan numbers up to n
        vector<long long> cat(n + 1, 0);
        cat[0] = cat[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                cat[i] += cat[j] * cat[i - j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            int left = idx;              // elements smaller than arr[i]
            int right = n - idx - 1;     // elements greater than arr[i]
            
            long long total = cat[left] * cat[right];
            ans.push_back((int)total);
        }
        return ans;
    }
};