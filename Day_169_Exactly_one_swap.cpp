#include <bits/stdc++.h>
using namespace std;

// Function to count the number of strings that can be formed by exactly one swap

class Solution {
    public:
        // Function to count the number of strings that can be formed by exactly one swap
        int countStrings(string &s) {
                int countofunique = 0; // To count unique characters in the string
                bool flag = false;     // To check if there is any duplicate character
                vector<int> v(26, 0);  // Frequency array for each lowercase letter

                // Count frequency of each character and check for duplicates
                for(auto c: s){
                        if(!flag && v[c-'a']) flag = true; // Set flag if duplicate found
                        if(v[c-'a'] == 0) countofunique++; // Count unique characters
                        v[c-'a']++;
                }

                long long ans = 0;
                int n = s.length();

                // Calculate the number of possible swaps
                for(int i = 0; i < 26; i++)
                {
                        int count = v[i];
                        int number = 0;
                        if(v[i] > 0)
                        {
                                // For each character, count how many swaps can be made with other characters
                                number = (n - v[i]) * v[i];
                                ans += number;
                        }
                }
                // Each swap is counted twice (i, j) and (j, i), so divide by 2
                ans /= 2;

                // If there is any duplicate character, we can swap two same characters and string remains same
                if(flag) 
                        ans++;

                return (int)ans;
        }
};
