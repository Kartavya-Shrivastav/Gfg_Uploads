#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of subarrays with at most k distinct integers.
// Approach: Use a sliding window technique with a map to keep track of the count of distinct integers.

// Steps:
// 1. Initialize two pointers, st and end, to represent the start and end of the current window.
// 2. Use a map to count the occurrences of each integer in the current window.
// 3. Expand the window by moving end to the right and adding the current integer to the map.
// 4. If the number of distinct integers exceeds k, shrink the window from the left by moving st to the right until there are
//    at most k distinct integers.
// 5. Keep track of the total number of valid subarrays during the process.

// Time Complexity: O(n), where n is the size of the input array.
// Space Complexity: O(k) for the map, as it can contain at most k distinct integers.

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        map<int, int> mp;
        int st=0;
        int end=0;
        int total=0;
        while(end< arr.size()){
            mp[arr[end]]++;
            while(mp.size()>k){
                mp[arr[st]]--;
                if(mp[arr[st]]==0){
                    mp.erase(arr[st]);
                }
                st++;
            }
            total= total+ (end-st+1);
            end++;
        }
        return total;
    }
};