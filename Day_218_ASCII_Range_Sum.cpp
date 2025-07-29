#include <bits/stdc++.h>
using namespace std;

// Problem: Calculate the ASCII range sum for characters in a string.
// Approach: For each character from 'a' to 'z', find the first and last occurrence in the string,
// and compute the sum of ASCII values of characters between these two occurrences.

// Steps:
// 1. Create a map to store the first and last occurrence of each character in the string.
// 2. Iterate through the string and populate the map.
// 3. For each character from 'a' to 'z', check if it has at least two occurrences.
// 4. If it does, calculate the sum of ASCII values of characters between the first and last occurrence.
// 5. Return a vector containing these sums.

// Time Complexity: O(n) where n is the length of the string, as we traverse the string once to build the map and then iterate through a fixed range of characters.
// Space Complexity: O(1) for the map since it only stores a fixed number of characters (26 lowercase letters).

class Solution {
  public:
    vector<int> asciirange(string& s) {
         unordered_map<char, vector<int>> mp;
        int n = s.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) mp[s[i]].push_back(i);
        for (char ch = 'a'; ch <= 'z'; ch++){
            if (mp[ch].size() >= 2){
                int f = mp[ch].front(), l = mp[ch].back();
                int sum = 0;
                for (int i = f+1; i < l; i++){
                    sum += s[i];
                }
                // cout << ch << endl;
                if (sum != 0) ans.push_back(sum);
            }
        }
        return ans;
    }
};