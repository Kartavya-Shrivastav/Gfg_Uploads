#include <bits/stdc++.h>
using namespace std;

// Problem: Given a number as a string, return the largest number possible by swapping two digits at most once
// Approach: Identify the first position where the current digit is less than the maximum digit found to its right, then swap it with the last occurrence of that maximum digit

// Steps:
// 1. Create a sorted version of the string in descending order.
// 2. Find the first index where the original string differs from the sorted string.
// 3. If no such index exists, return the original string.
// 4. Otherwise, find the last occurrence of the digit from the sorted string in the original string and swap them.
// 5. Return the modified string.

// Time Complexity: O(N) where N is the length of the string
// Space Complexity: O(N) for storing the sorted string

class Solution {
  public:
    string largestSwap(string &s) {
        int n=s.size();
        int ind=0;
        string t=s;
        sort(t.begin(), t.end(),greater<int>());
        int d =-1;
        for(int i=0;i<n;i++){
            if(t[i]!=s[i])
            {
                d=i;
                break;
            }
        }
        if (d==-1) return s;
        for(int i=n-1;i>=0;i--){
            if(t[d]==s[i]){
                swap(s[d],s[i]);
                break;
            }
        }
        
        return s;
    }
};