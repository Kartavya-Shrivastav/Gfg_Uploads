
class Solution {
  public:
    int height(Node* root){
        if(root == NULL) return 1;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        return max(lh, rh)+1;
    }
  
    int minTime(Node* root, int target) {
        return height(root)-1;
    }
};