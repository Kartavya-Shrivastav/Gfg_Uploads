#include <bits/stdc++.h>
using namespace std;
// Function to find the sum of all substrings of a number represented as a string
// Time Complexity: O(n^2), where n is the length of the string
// Space Complexity: O(1), as we are using a constant amount of extra space
class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
         set<int> sets;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] <= 0) continue;
            sets.insert(arr[i] * arr[i]);
        }
        for(int a : sets) {
            for(int b : sets) {
                if(sets.find(a + b) != sets.end()) return true;
            }
        }
        return false;
    }
};