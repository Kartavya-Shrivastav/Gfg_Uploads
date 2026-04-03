
class Solution {
  public:
    vector<int>solve(Node* node){
        if(!node){
            return {0, 1e9, -1e9};
        }
        if(!node->left && !node->right){
            return {1, node->data, node->data};
        }
        
        vector<int>lft=solve(node->left);
        vector<int>rgt=solve(node->right);
        
        if(node->data>lft[2] && node->data<rgt[1]){
            return {lft[0]+rgt[0]+1, min(lft[1], node->data),
                max(node->data, rgt[2])};
        }else return {max(rgt[0], lft[0]), -1e9, 1e9};
    }
    
    int largestBst(Node *root) {
        // Your code here
        return solve(root)[0];
    }
};