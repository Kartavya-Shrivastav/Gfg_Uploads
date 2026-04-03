#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary tree where each node represents a pile of candies, and each pile has a certain number of candies. The goal is to distribute the candies such that each node has exactly one candy. You can only move one candy at a time from one node to an adjacent node (parent or child). Find the minimum number of moves required to achieve this distribution.
Approach: To solve this problem, we can use a depth-first search (DFS) approach. We will traverse the tree and calculate the excess or deficit of candies at each node. The number of moves required to balance the candies at each node will be the sum of the absolute values of the excess or deficit from its left and right children. We will also keep track of the total moves required as we traverse the tree.

Steps:
1. Perform a DFS traversal of the tree.
2. For each node, calculate the excess or deficit of candies by taking the number of candies at the node plus the excess or deficit from its left and right children, minus one (since we want one candy at each node).
3. The number of moves required to balance the candies at each node will be the sum of the absolute values of the excess or deficit from its left and right children.
4. Keep track of the total moves required as we traverse the tree.

Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once during the DFS traversal.
Space Complexity: O(H) where H is the height of the tree, due to the recursive call stack during the DFS traversal. In the worst case (skewed tree), this can be O(N).
*/


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        dfs(root, moves);
        return moves;
    }
    
private:
    int dfs(Node* node, int& moves) {
        if (!node) return 0;
        int left = dfs(node->left, moves);
        int right = dfs(node->right, moves);
        moves += abs(left) + abs(right);
        return node->data + left + right - 1;
    }
};