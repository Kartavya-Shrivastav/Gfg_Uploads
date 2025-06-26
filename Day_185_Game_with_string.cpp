#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum Value to Get Positive Step by Step Sum
// Aproach: Use a max heap to keep track of character frequencies and reduce them iteratively.

// Steps:
// 1. Count the frequency of each character in the string.
// 2. Store the frequencies in a max heap (priority queue).
// 3. For k iterations, pop the maximum frequency, reduce it by 1, and push it back into the heap.
// 4. After k iterations, calculate the sum of squares of the remaining frequencies.

// Time Complexity: O(n + k log n), where n is the length of the string and k is the number of iterations.
// Space Complexity: O(n), for storing the frequencies in a vector and the heap.

class Solution {
    public:
        int minValue(string &s, int k) {
                priority_queue<int> pq; // Max heap to store character frequencies
                vector<int> v(26, 0);   // Frequency array for 26 lowercase letters

                // Count frequency of each character in the string
                for (auto &b : s) {
                        v[b - 'a']++;
                }

                // Push non-zero frequencies into the max heap
                for (auto &b : v) {
                        if (b != 0) {
                                pq.push(b);
                        }
                }

                // Perform k operations: each time reduce the highest frequency by 1
                while (k--) {
                        int x = pq.top(); pq.pop();
                        x--;
                        pq.push(x);
                }

                int ans = 0;
                // Calculate the sum of squares of the remaining frequencies
                while (pq.size()) {
                        ans += (pq.top() * pq.top());
                        pq.pop();
                }
                return ans;
        }
};