#include <bits/stdc++.h>
using namespace std;

// Problem: All Palindromic Partitions
// Approach: Backtracking

// Steps:
// 1. Define a function to check if a string is a palindrome.
// 2. Use backtracking to explore all possible partitions of the string.
// 3. For each partition, check if the substring is a palindrome.
// 4. If it is, add it to the current partition and continue exploring.
// 5. If the end of the string is reached, add the current partition to the result.
// 6. Return the result containing all palindromic partitions.

// Time Complexity: O(2^n * n) where n is the length of the string
// Space Complexity: O(n) for the recursion stack and temporary storage

class Solution {
  public:
    vector<vector<string>> res;
    
    bool check(string &s){
        int start = 0 , end = s.length()-1;
        while(start <= end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    void solve(string &s , int i , vector<string>&temp){
        if(i >= s.length()){
            res.push_back(temp);
            return;
        }
        
        string tmp;
        for(int j=i;j<s.length();j++){
            tmp.push_back(s[j]);
            if(check(tmp)){
                temp.push_back(tmp);
                solve(s,j+1,temp);
                temp.pop_back();
            }
        }
    }
  
    vector<vector<string>> palinParts(string &s) {
        vector<string> temp;
        solve(s,0,temp);
        return res;
    }
};