#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers arr and an integer k, return the number of pairs (i, j) where i < j and (arr[i] XOR arr[j]) < k.
// Approach: Use a Trie to store the binary representation of numbers. For each number, we query the Trie to count how many previously inserted numbers yield an XOR less than k.

// Steps:
// 1. Define a Trie structure with two children (0 and 1) and a count of numbers passing through each node.
// 2. Implement an insert function to add numbers to the Trie in their binary form.
// 3. Implement a query function to count how many numbers in the Trie yield an XOR with the current number that is less than k.
// 4. For each number in the array, use the query function to count valid pairs and then insert the number into the Trie.
// 5. Return the total count of valid pairs.

// Time Complexity: O(n * log M), where n is the number of elements in arr and M is the maximum value in arr (assuming 16 bits for integers).
// Space Complexity: O(n * log M) for storing numbers in the Trie.

class Solution {
public:
    struct Trie{
        Trie* child[2];
        int cnt;
        Trie(){
            child[0]=child[1]=nullptr;
            cnt=0;
        }
    };

    Trie* root=new Trie();

    // Insert a number into trie
    void insert(int x){
        Trie* node=root;
        for (int i=15;i>=0;i--){
            int bit=(x>>i)&1;
            
            if(!node->child[bit]){
                node->child[bit]=new Trie();
            }
                
            node = node->child[bit];
            node->cnt++;
        }
    }

    // Query: count numbers already inserted such that (x XOR y) < k
    int query(int x,int k) {
        Trie* node=root;
        int res = 0;
        for (int i = 15;i>=0;i--){
            if(!node){
                break;
            }
            
            int xb=(x>>i) & 1;
            int kb=(k>>i) & 1;

            // Case: kb == 1 → add subtree where XOR bit = 0
            if (kb==1){
                int want = xb;  // XOR = 0 → bits same
                if (node->child[want]){
                    res+=node->child[want]->cnt;
                }
                    
                node=node->child[xb ^ 1];  // move to XOR = 1 branch
            } 
            else { // kb == 0 → must go only to XOR = 0 path
                int want = xb;
                node=node->child[want];
            }
        }
        return res;
    }

    int cntPairs(vector<int>& arr, int k) {
        int ans=0;
        for (int x : arr) {
            ans+=query(x, k); // count valid earlier pairs
            insert(x);
        }
        
        return ans;
    }
};