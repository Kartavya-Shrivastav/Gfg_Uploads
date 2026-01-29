#include <bits/stdc++.h>
using namespace std;

// Problem: First Non-Repeating Character in a Stream
// Given a stream of lowercase alphabets, for each character added to the stream, find the first non-repeating character in the stream so far. If there is no such character, return '#'.
// Approach: Use a frequency array to keep track of character counts and a queue to maintain the order of characters as they appear in the stream.

// Steps:
// 1. Initialize a frequency array of size 26 (for each lowercase alphabet) to zero.
// 2. Initialize an empty queue to store characters.
// 3. For each character in the stream:
//    a. Increment its frequency in the frequency array.    
//    b. If its frequency becomes 1, push it into the queue.
//    c. While the queue is not empty and the frequency of the character at the front of the queue is greater than 1, pop it from the queue.
//    d. If the queue is not empty, the front of the queue is the first non-repeating character; otherwise, return '#'.
// 4. Replace the character in the stream with the first non-repeating character found in step 3d.

// Time Complexity: O(N) where N is the length of the stream, as each character is processed once.
// Space Complexity: O(1) since the frequency array and queue size are bounded by the number of lowercase alphabets (26).

class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        int n = s.length();
        vector<int> freq(26, 0);
        queue<int> q;
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            if(freq[s[i] - 'a'] == 1) q.push(s[i]);
            while(!q.empty() && freq[q.front() - 'a'] != 1) q.pop();
            if(!q.empty()) s[i] = q.front();
            else s[i] = '#';
        }
        return s;
    }
};