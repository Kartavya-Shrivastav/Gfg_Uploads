
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
         vector<int> temp1;
        if(root == NULL) return temp1;
        vector<vector<int>> temp;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        temp1.push_back(root->data);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr == NULL){
                if(!q.empty()){
                    q.push(NULL);
                    temp.push_back(temp1);
                    temp1.clear();
                }
            } else{
                temp1.push_back(curr->data);
                if(curr->left){
                    q.push(curr->left);
                }
                
                if(curr->right){
                    q.push(curr->right);
                }
            }
        }
        temp.push_back(temp1);
        temp1.clear();
        
        for(int i=0; i<temp.size(); i++){
            temp1.push_back(temp[i][0]);
        }
        
        return temp1;
    }
};