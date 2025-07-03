#include <bits/stdc++.h>
using namespace std;

// Problem: Find the length of the longest substring with exactly k distinct characters.
// Approach: Use a sliding window technique with a hash map to keep track of the count of distinct characters.

// Steps:
// 1. Initialize two pointers, i and j, to represent the start and end of the current window.
// 2. Use a map to count the occurrences of each character in the current window.
// 3. Expand the window by moving j to the right and adding the current character to the map.
// 4. If the number of distinct characters exceeds k, shrink the window from the left by moving i to the right until there are
//    exactly k distinct characters.
// 5. Keep track of the maximum length of the window during the process.

// Time Complexity: O(n), where n is the size of the input string.
// Space Complexity: O(k) for the map, as it can contain at most k distinct characters.


class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int> mp;
        int maxAns=-1;
        // traverse on the string
        int j=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        // calculate max value if we have excatly k distinct character
            if(mp.size()==k){
                int len=i-j+1;
                maxAns=max(maxAns,len);
            }
            // shrink window only if size of map is greater than k
            if(mp.size()>k){
                // remove value at jth pos
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
                
            }
        }
        return maxAns;
    }
    
};