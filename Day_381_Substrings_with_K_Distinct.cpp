#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a string s and an integer k, return the number of substrings with exactly k distinct characters.    
// Approach: Sliding Window / Two Pointers

// Steps:
// 1. Define a helper function f(k) that counts the number of substrings with at most k distinct characters
// 2. Use a sliding window approach with two pointers to maintain a window that contains at most k distinct characters
// 3. Iterate through the string, expanding the right pointer and updating the count of distinct characters using a frequency array
// 4. When the count of distinct characters exceeds k, move the left pointer to reduce the count
// 5. For each position of the right pointer, count the number of valid substrings that can be formed with at most k distinct characters and add to the result
// 6. The result for exactly k distinct characters is obtained by subtracting f(k+1) from f(k)

// Time Complexity: O(n) where n is the length of the string
// Space Complexity: O(1) since the frequency array size is fixed (26 for lowercase English letters)

class Solution {
  public:
    int countSubstr(string& s, int k) {
        int n=s.size();
        auto f=[&] (int  k) ->int{
            int ans=0;
            vector<int> m(26,0);
            int cnt=0;
            for(int i=0,j=0;i<n;i++){
                if(m[s[i] - 'a'] == 0) cnt++;
                m[s[i]-'a']++;
                
                while(cnt >= k){
                    ans+=n-i;
                    m[s[j] - 'a']--;
                    if(m[s[j] - 'a'] == 0) cnt--;
                   

                    j++;
                }
            }
            return ans ;
        };
        return f(k)-f(k+1);
    }
};