#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string A and a dictionary of strings B, determine if A can be segmented into a space-separated sequence of one or more dictionary words from B.
// Approach: We can use a Trie data structure to store the dictionary words and then use a recursive function to check if the string A can be segmented using the words in the Trie.

// Steps:
// 1. Create a Trie node structure to represent each character in the dictionary words.
// 2. Insert each word from the dictionary B into the Trie.
// 3. Implement a search function to check if a substring exists in the Trie.
// 4. Use a recursive function to check if the string A can be segmented by checking all possible prefixes and recursively checking the remaining substring.

// Time Complexity: O(n * m), where n is the length of string A and m is the average length of words in B.
// Space Complexity: O(k), where k is the total number of characters in all words in B.

// Trie node structure
struct node{
    node *child[26]; // Pointers to child nodes for each alphabet letter
    bool isEnd;      // Flag to indicate end of a word

    node(){
        for(int i=0;i<26;i++){
            child[i]=NULL; // Initialize all children as NULL
            isEnd=false;   // Mark as not end of word
        }
    }
};

// Insert a word into the Trie
void insert(node *root, string s){
    for(int i=0; i<s.length(); i++){
        if(root->child[s[i]-'a']) // If child exists, move to it
            root = root->child[s[i]-'a'];
        else{
            root->child[s[i]-'a'] = new node(); // Create new node if not present
            root = root->child[s[i]-'a'];
        }
    }
    root->isEnd = true; // Mark end of word
}

class Solution{
public:
    // Search if a word exists in the Trie
    bool search(node *root, string A){
        int n = A.length();
        node *temp = root;

        for(int i=0; i<n; i++){
            if(!temp->child[A[i]-'a']) // If child doesn't exist, word not found
                return false;
            temp = temp->child[A[i]-'a'];
        }

        return (temp && temp->isEnd); // Return true if end of word is reached
    }

    // Recursive function to check if string can be segmented
    bool solve(node *root, string s){
        int n = s.length();
        if(n == 0) return true; // If string is empty, segmentation is possible

        // Try all prefixes of the string
        for(int i=1; i<=n; i++){
            // If prefix exists in Trie and remaining string can be segmented
            if (search(root, s.substr(0, i)) && solve(root, s.substr(i, n-i)))
                return true;
        }
        return false; // No valid segmentation found
    }
    
    // Main function to check if word break is possible
    int wordBreak(string A, vector<string> &B) {
        node *root = new node();

        // Insert all dictionary words into Trie
        for(auto it : B)
            insert(root, it);
        
        // Check if string A can be segmented
        return solve(root, A);
    }
};