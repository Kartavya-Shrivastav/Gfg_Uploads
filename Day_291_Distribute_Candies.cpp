
class Solution {
  public:
  int solve(int& ans,Node*root){
      if(root==NULL){
          return 0;
      }
      int left=solve(ans,root->left);
      int right=solve(ans,root->right);
      ans+=abs(left)+abs(right);
      return left+right+root->data-1;
  }
    int distCandy(Node* root) {
        int ans=0;
        solve(ans,root);
        return ans;
    }
};