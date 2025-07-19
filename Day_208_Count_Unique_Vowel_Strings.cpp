#include<bits/stdc++.h>
using namespace std;

/*
Problem Statement: Given a string, count the number of vowels and compute a specific product based on the frequency and diversity of vowels.
Approach: Use a map to count distinct vowels and their frequencies, then compute factorial-like and multiplicative expression.

Step-by-step Procedure:
1. Initialize a map to store the frequency of each vowel found in the string.
2. Iterate over each character in the string and update the vowel count if it is one of a, e, i, o, u.
3. Determine the number of distinct vowels (`sz`) and initialize the result `ans` with `sz`.
4. Multiply `ans` by factorial of `sz - 1`, starting from 2 to `sz - 1`.
5. Multiply `ans` with the frequency of each vowel from the map.

Time Complexity: O(n + v), where n is string length and v (≤5) is the number of distinct vowels.
Space Complexity: O(1), as the map stores at most 5 vowel entries.
*/

class Solution {
  public:
    int vowelCount(string& s) {
        map<char, int> mp;
        for(char c: s)
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') mp[c]++;
        int sz = mp.size(), ans = sz;
        for(int i = 2; i<sz; i++) ans *= i;
        for(auto it: mp) ans *= it.second;
        return ans;
    }
};