#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution{
public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        vector<int> currentPath;
        dfs(root, currentPath, result);
        return result;
    }

    void dfs(Node* node, vector<int>& path, vector<vector<int>>& result) {
        if (node == NULL) return;

        path.push_back(node->data);

        if (node->left == NULL && node->right == NULL) {
            result.push_back(path);  
        } else {
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }

        path.pop_back();  
    }
};