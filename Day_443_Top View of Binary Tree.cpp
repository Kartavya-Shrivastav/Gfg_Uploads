#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary tree, return the top view of the binary tree. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top. The nodes should be returned in order from left to right.
Approach: We can use a level order traversal (BFS) to traverse the tree and keep track of the horizontal distance (HD) of each node from the root. The root node has a horizontal distance of 0, the left child has a horizontal distance of -1, and the right child has a horizontal distance of +1. We will use a map to store the first node encountered at each horizontal distance. As we traverse the tree, if we encounter a node at a horizontal distance that is not already in the map, we will add it to the map. Finally, we will extract the values from the map in order of their keys (horizontal distances) to get the top view of the binary tree.

Steps:
1. Initialize an empty vector to store the answer and a map to store the first node at each horizontal distance.
2. Use a queue to perform a level order traversal of the tree. The queue will store pairs of nodes and their corresponding horizontal distances.
3. Start the traversal by pushing the root node with a horizontal distance of 0 into the queue.
4. While the queue is not empty, do the following:
    a. Pop the front element from the queue, which will give us the current node and its horizontal distance.
    b. If the horizontal distance is not already in the map, add the current node's value to the map with the horizontal distance as the key.
    c. If the current node has a left child, push it into the queue with a horizontal distance of (current horizontal distance - 1).
    d. If the current node has a right child, push it into the queue with a horizontal distance of (current horizontal distance + 1).
5. After the traversal is complete, iterate through the map in order of keys (horizontal distances) and add the corresponding node values to the answer vector.

Time complexity of this approach is O(n log n) due to the map operations, where n is the number of nodes in the binary tree. The space complexity is O(n) for the queue and the map.
Space complexity is O(n) for the queue and the map, where n is the number of nodes in the binary tree.
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;

        // Map: HD → Node value
        map<int,int> mp;

        // Queue: node + horizontal distance
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int hd = it.second;

            // Store first node at this HD
            if(mp.find(hd) == mp.end())
                mp[hd] = node->data;

            if(node->left)
                q.push({node->left, hd-1});

            if(node->right)
                q.push({node->right, hd+1});
        }

        // Extract answer in order
        for(auto x : mp)
            ans.push_back(x.second);

        return ans;
    }
};