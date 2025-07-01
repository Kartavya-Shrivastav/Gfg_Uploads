#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of substrings of length k with exactly k-1 distinct characters.
// Approach: Use a sliding window technique with a map to count distinct characters.

// Steps:
// 1. Initialize a map to keep track of character counts.
// 2. Use two pointers (i and j) to maintain the window.
// 3. Expand the window by moving j and include the character at j in the map
// 4. If the window size exceeds k, shrink it from the left by moving i and updating the map.
// 5. If the size of the map equals k-1, increment the answer.
// 6. Continue until j reaches the end of the string.

// Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(k), where k is the number of distinct characters in the substring.

class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
         map<int,int> mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            if(j-i+1>=k){
                while(j-i+1>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)mp.erase(s[i]);
                    i++;
                }
                if(mp.size()==k-1)ans++;
            }
            j++;
        }
        return ans;
    }
};