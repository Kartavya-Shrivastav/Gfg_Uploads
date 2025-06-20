#include <bits/stdc++.h>
using namespace std;

// Problem: Word Ladder I
// Approach: Use BFS to find the shortest transformation sequence from startWord to targetWord.

// Steps:
// 1. Initialize a queue to perform BFS, starting with the startWord and step count
// 2. Use an unordered set to store the wordList for O(1) lookups.
// 3. While the queue is not empty, pop the front element and check if it matches the targetWord
// 4. If it matches, return the step count.

// Time Complexity: O(N * M * 26) where N is the number of words in wordList, M is the length of each word.
// Space Complexity: O(N) for the queue and set.

class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Initialize a queue for BFS; each element is a pair of (current word, current step count)
        queue<pair<string,int>> q;
        q.push({startWord, 1});

        // Use an unordered_set for fast lookup of words in the wordList
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Remove the startWord from the set to avoid revisiting
        st.erase(startWord);

        // Perform BFS
        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            // If the current word matches the target, return the number of steps
            if (word == targetWord) return step;

            // Try changing each character of the current word to every possible lowercase letter
            for (int i = 0; i < word.size(); i++) {
            char org = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                // If the new word exists in the set, add it to the queue and remove from set
                if (st.find(word) != st.end()) {
                st.erase(word);
                q.push({word, step + 1});
                }
            }
            // Restore the original character before moving to the next position
            word[i] = org;
            }
        }
        // If transformation is not possible, return 0
        return 0;
    }
};