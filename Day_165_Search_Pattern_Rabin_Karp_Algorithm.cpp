#include <bits/stdc++.h>
using namespace std;
// This code defines a Solution class with a method to search for anagrams of a pattern in a given text using frequency counting.

class Solution {
    public:
        // Function to search for all occurrences of the pattern 'pat' in the text 'txt'
        vector<int> search(string &pat, string &txt) {
                int n = txt.length();
                int m = pat.length();
                
                vector <int> ans; // Stores starting indices (1-based) of pattern matches
                vector <int> freqPt(26, 0); // Frequency count for pattern characters
                vector <int> freqTxt(26, 0); // Frequency count for current window in text
                
                // Initialize frequency arrays for pattern and first window of text
                for(int i = 0; i < m; i++){
                        freqPt[pat[i] - 'a']++;
                        freqTxt[txt[i] - 'a']++;
                }
                
                // Slide the window over the text
                for(int i = 0; i <= n-m; i++){
                        // If frequency arrays match, check for exact substring match
                        if(freqPt == freqTxt){
                                bool match = true;
                                for(int j = 0; j < m; j++){
                                        if(pat[j] != txt[i + j]){
                                                match = false;
                                                break;
                                        }
                                }
                                
                                if(match) ans.push_back(i+1); // Store 1-based index
                        }
                        
                        // Move the window: remove the first character and add the next character
                        if (i + m < n) {
                                freqTxt[txt[i] - 'a']--;
                                freqTxt[txt[i + m] - 'a']++;
                        }
                }
                
                return ans; // Return all starting indices of matches
        }

};