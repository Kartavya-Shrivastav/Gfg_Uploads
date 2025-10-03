#include <bits/stdc++.h>
using namespace std;

// Problem: Possible Words From Phone Digits
// Approach: We can use backtracking to generate all possible words from the given phone digits.

// Steps:
// 1. Create a mapping of digits to their corresponding characters as per a traditional phone keypad.
// 2. Define a recursive function that builds words by appending characters corresponding to each digit.
// 3. When a word is formed (i.e., when the current index reaches the size of the input array), add it to the result list.
// 4. Use backtracking to explore all combinations of characters for the given digits.
// 5. Finally, return the list of possible words.

// Time Complexity: O(4^n) in the worst case (for digits like 7 and 9 which map to 4 letters)
// Space Complexity: O(n) for the recursion stack and O(m) for storing the results

class Solution {
  public:
    vector<string> ans;
    unordered_map<int, string> mp;
    void solve(int i, int& n, string s, vector<int>& arr){
        if (i == n){
            ans.push_back(s);
            return;
        }
        if (arr[i] <= 1){
            solve(i+1, n, s, arr);
            return;
        }
        for (char ch : mp[arr[i]]){
            solve(i+1, n, s+ch, arr);
        }
    }
    
    vector<string> possibleWords(vector<int> &arr) {
        int n = arr.size();
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        solve(0, n, "", arr);
        return ans;
    }
};