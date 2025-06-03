#include <bits/stdc++.h>
using namespace std;

/*
This code defines a Solution class with a method to count the number of substrings in a given string that contain exactly k distinct characters.
The method iterates through all possible substrings, maintaining a frequency count of characters and counting distinct characters. It increments the count when the number of distinct characters matches k.
*/

class Solution {
    public:
        // Function to count substrings with exactly k distinct characters
        int countSubstr(string &s, int k){
                int count = 0;
                // Iterate over all possible starting indices of substrings
                for (int i = 0; i < s.size(); i++){
                        vector<int> freq(26, 0); // Frequency array for characters 'a' to 'z'
                        int distinct = 0; // Number of distinct characters in current substring
                        // Iterate over all possible ending indices for the current starting index
                        for (int j = i; j < s.size(); j++){
                                // If character s[j] is seen for the first time in this substring
                                if (freq[s[j] - 'a'] == 0)
                                        distinct++;

                                freq[s[j] - 'a']++; // Increment frequency of current character
                                
                                // If the number of distinct characters is exactly k, increment count
                                if (distinct == k)
                                        count++;

                                // If distinct characters exceed k, break out of the loop
                                if (distinct > k)
                                        break;
                        }
                }
                return count; // Return the total count of valid substrings
        }
};