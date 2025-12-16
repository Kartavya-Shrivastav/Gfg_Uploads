#include <bits/stdc++.h>
using namespace std;

// Problem: Given two strings `s1` and `s2`, determine if `s2` is a rotation of `s1`.
// Approach: Concatenate `s1` with itself and check if `s2` is a substring of the result.

// Steps:
// 1. Check if the lengths of `s1` and `s2` are equal. If not, return false.
// 2. Concatenate `s1` with itself to form a new string `t`.
// 3. Check if `s2` is a substring of `t`. If it is, return true; otherwise, return false.
// 4. Return the result.

// Complexity Analysis:
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length())
        return false;

        string t = s1 + s1;
        return t.find(s2) < t.length();
    }
};   