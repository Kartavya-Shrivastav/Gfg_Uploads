#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        // Custom comparator for sorting pairs
        // Sort by absolute difference first (ascending)
        // If difference is same, sort by value (descending)
        static bool customCompare(pair<int, int> a, pair<int, int> b) {
                if (a.first == b.first) {
                        return a.second > b.second;
                }
                return a.first < b.first;
        }
        
        // Function to find k closest elements to x in arr
        vector<int> printKClosest(vector<int> arr, int k, int x) {
                vector<pair<int, int>> diff; // Store (difference, value) pairs
                
                // Compute absolute differences and store pairs, skip if value is x
                for (int a : arr) {
                        if (a == x) continue;
                        diff.push_back({abs(a - x), a});
                }
                
                // Sort pairs using custom comparator
                sort(diff.begin(), diff.end(), customCompare);
                
                vector<int> result;
                // Collect the k closest elements
                for (int i = 0; i < k; i++) {
                        result.push_back(diff[i].second);
                }
                return result;
        }
};