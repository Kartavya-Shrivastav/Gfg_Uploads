#include <bits/stdc++.h>
using namespace std;

// Problem: Function to find the smallest window in s that contains all characters of p
// Approach: Use sliding window technique with two pointers

// Steps:
// 1. Create two frequency arrays to count characters in p and the current window in s.
// 2. Use two pointers to represent the current window in s.
// 3. Expand the right pointer to include characters until all characters of p are included.
// 4. Contract the left pointer to find the minimum window that still contains all characters of p.
// 5. Return the smallest window found or an empty string if no such window exists.

// Time Complexity: O(n), where n is the length of the string s
// Space Complexity: O(1), since the frequency arrays have a fixed size of 26

class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        vector<int> countp(26,0);
        vector<int> counts(26,0);
        
        if (p.size()>s.size())
        return "";
        int distinctp=0,len=s.size(),match=0;
        
        for (int i=0;i<p.size();i++){
            if (countp[p[i]-'a']==0)
            distinctp++;
            
            countp[p[i]-'a']++;
        }
        
        int left=0,right=0,start=0,end=s.size()-1;
        while (right<s.size()){
            counts[s[right]-'a']++;
            
            if (counts[s[right]-'a']==countp[s[right]-'a'])
            match++;
            
            if (match==distinctp){
                while (counts[s[left]-'a']>countp[s[left]-'a']){
                    counts[s[left]-'a']--;
                    left++;
                }
                if (len>right-left+1){
                    start=left;
                    end=right;
                    len=right-left+1;
                }
            }
            
            right++;
        }
        string ans="";
        if (match<distinctp)
            return "";
        else
        {
            for (int i=start;i<=end;i++){
                ans+=s[i];
            }
            return ans;
        }
    }
};