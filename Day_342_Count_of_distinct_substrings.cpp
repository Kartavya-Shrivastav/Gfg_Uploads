#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string s, return the count of distinct substrings of s.
// Approach: Use a Trie (prefix tree) to store all substrings of the given string. Each time we insert a new character that does not exist in the current path of the Trie, it indicates a new distinct substring.

// Steps:
// 1. Initialize a TrieNode structure to represent each node in the Trie.   
// 2. For each starting index in the string, insert all substrings starting from that index into the Trie.
// 3. Count the number of new nodes created during the insertion process, which corresponds to the number of distinct substrings.
// 4. Return the count of distinct substrings.

// Time Complexity: O(n^2) in the worst case, where n is the length of the string, as we may need to insert n substrings each of length up to n.
// Space Complexity: O(n^2) in the worst case for storing all distinct substrings

class Solution {
  public:
    struct TrieNode{
    	TrieNode* child[26];
    	TrieNode(){
    		for(int c=0;c<26;c++)
                child[c]=NULL;
    	}
    };
    int countSubs(string& s) {
       TrieNode* root=new TrieNode();
       int n=s.size(),ans=0;
       for(int i=0;i<n;i++){
           TrieNode* curr=root;
           for(int j=i;j<n;j++){
               int req=s[j]-'a';
               if(curr->child[req]==NULL){
                   ans++;
                   curr->child[req]=new TrieNode();
               }
               curr=curr->child[req];
           }
       }
       return ans;
    }
};