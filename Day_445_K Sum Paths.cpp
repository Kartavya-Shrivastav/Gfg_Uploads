#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary tree and an integer k, return the count of all paths in the tree that sum up to k. A path can start and end at any node in the tree, but it must go downwards (traveling only from parent nodes to child nodes).
Approach: We can use a depth-first search (DFS) approach to traverse the tree while keeping track of the cumulative sum of the path from the root to the current node. We can use a hash map to store the frequency of cumulative sums encountered so far. For each node, we check if there is a cumulative sum that equals the current cumulative sum minus k, which indicates that there is a path that sums up to k.

Steps:
1. Initialize a hash map to store the frequency of cumulative sums, starting with a cumulative sum of 0 having a frequency of 1 (to account for paths that start from the root).
2. Define a recursive DFS function that takes the current node, the target sum k, the current cumulative sum, and the hash map as parameters.
3. In the DFS function:
    a. If the current node is null, return 0.
    b. Add the current node's value to the cumulative sum.
    c. Check if there is a cumulative sum in the hash map that equals (current cumulative sum - k). If it exists, add its frequency to the count of valid paths.
    d. Increment the frequency of the current cumulative sum in the hash map.
    e. Recursively call the DFS function for the left and right child nodes, adding their results to the count.
    f. After exploring both child nodes, decrement the frequency of the current cumulative sum in the hash map to backtrack.
4. Return the total count of valid paths.

Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(N) in the worst case for the hash map and the recursion stack.
*/

class Solution {
public:
    int countAllPaths(Node* root, int k) {
        unordered_map<long long, int> prefixSum{{0, 1}};
        return dfs(root, k, 0, prefixSum);
    }
    
private:
    int dfs(Node* node, int k, long long sum, unordered_map<long long, int>& mp) {
        if (!node) return 0;
        
        sum += node->data;
        int count = mp[sum - k];
        
        mp[sum]++;
        count += dfs(node->left, k, sum, mp);
        count += dfs(node->right, k, sum, mp);
        mp[sum]--;
        
        return count;
    }
};