#include <bits/stdc++.h>
using namespace std;

// Problem: Find the leftmost and rightmost index of an element in a vector
// Approach: Iterate through the vector to find the first and last occurrence of the element.

// Steps:
// 1. Initialize two variables to store the first and last index, both set to -1 initially.
// 2. Loop through the vector to find the first occurrence of the element.
// 3. If found, store the index in the first variable and continue to find the last occurrence.
// 4. Loop through the vector in reverse to find the last occurrence of the element.
// 5. Return a pair containing the first and last index.

// Time Complexity: O(N), where N is the size of the vector.
// Space Complexity: O(1), as we are using only a few extra variables.

class Solution {
public:
    pair<long, long> indexes(vector<long long> v, long long x) {
        long first = -1, last = -1;
        int n = v.size();
        for (int i = 0; i < n; i++) {
            if (v[i] == x) {
                first = i;
                break;
            }
        }

        for (int j = n - 1; j >= 0; j--) {
            if (v[j] == x) {
                last = j;
                break;
            }
        }

        return {first, last};
    }
};

