#include <bits/stdc++.h>
using namespace std;

// Problem: Find the minimum time difference between any two time strings in a list
// Approach: Convert time strings to seconds, sort them, and calculate the differences.

// Steps:
// 1. Convert each time string into total seconds from the start of the day.
// 2. Store these seconds in a vector.
// 3. Sort the vector of seconds.
// 4. Calculate the differences between consecutive times in the sorted vector.
// 5. Also calculate the difference between the last and first time to account for wrap-around.
// 6. Return the minimum difference found.

// Time Complexity: O(n log n), where n is the number of time strings (due to sorting)
// Space Complexity: O(n), for storing the converted times in a vector

class Solution {
  public:
    int minDifference(vector<string> &arr) {
        int n=arr.size();
        vector<long long>ans;
        for(string ch:arr)
        {
            int hr=stoi(ch.substr(0,2));
            int min=stoi(ch.substr(3,2));
            int sec=stoi(ch.substr(6,2));
            
            
            long long total=hr*3600+min*60+sec;
            ans.push_back(total);
        }
        
        sort(ans.begin(),ans.end());
        long long maxi=INT_MAX;
        for(int i=1;i<n;i++)
        {
            long long diff=ans[i]-ans[i-1];
            maxi=min(maxi,diff);
        }
         long long wrapDiff = 86400 - ans[n - 1] + ans[0];
         maxi = min(maxi, wrapDiff);

        return (int)maxi;
    }
};