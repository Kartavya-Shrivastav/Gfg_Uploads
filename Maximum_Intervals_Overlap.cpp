#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum number of guests present at any time in a party given entry and exit times.
// Approach: Use a map to track the number of guests entering and exiting at each time point.

class Solution {
    public:
        vector<int> findMaxGuests(int Entry[], int Exit[], int N) {
                // Map to store the net change in guest count at each time point
                map<int, int> mp;
                // Increment at entry time, decrement at exit+1 time
                for(int i = 0; i < N; i++) {
                        mp[Entry[i]]++;      // Guest enters
                        mp[Exit[i]+1]--;     // Guest leaves after exit time
                }
                int cnt = 0;             // Current number of guests
                int max_cnt = 0;         // Maximum number of guests at any time
                vector<int> ret(2);      // ret[0]: max guests, ret[1]: time of max guests
                // Traverse the map in time order
                for(auto &x : mp){
                        cnt += x.second;     // Update current guest count
                        if(cnt > max_cnt) {  // Check if current count is the new maximum
                                max_cnt = cnt;
                                ret[0] = max_cnt;
                                ret[1] = x.first; // Record the time of max guests
                        }
                }
                return ret;              // Return max guests and the time it occurred
        }
};