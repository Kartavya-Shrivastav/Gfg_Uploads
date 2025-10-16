

class Solution {
    void createArray(Node *root, vector<int>& temp){
        if(root == NULL){
            return;
        }
        
        createArray(root->left, temp);
        temp.push_back(root->data);
        createArray(root->right, temp);
        
        return;
    }
  public:
    int kthSmallest(Node *root, int k) {
        vector<int> temp;
        createArray(root, temp);        
        int n = temp.size();
        if(n < k){
            return -1;
        }
        return temp[k-1];
    }
};