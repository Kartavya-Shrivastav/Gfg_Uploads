#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers and an integer k, count the number of subarrays with at most k distinct integers.    
// Approach: Two Pointers / Sliding Window

// Steps:
// 1. Use two pointers to maintain a window that contains at most k distinct integers
// 2. Iterate through the array, expanding the right pointer and updating the count of distinct integers using a hash map
// 3. When the count of distinct integers exceeds k, move the left pointer to reduce the count
// 4. For each position of the right pointer, count the number of valid subarrays that can be formed with at most k distinct integers and
//    add to the result
// 5. Return the total count of such subarrays

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(k) for the hash map storing counts of distinct integers

class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int l=0, ans=0;       
        for (int r=0; r<arr.size(); r++) {
            mp[arr[r]]++;
            while (mp.size()>k) {
                mp[arr[l]]--;
                if (mp[arr[l]] == 0) mp.erase(arr[l]);
                l++;
            }
            
            ans += r-l+1;
        }
        return ans;
    }
};