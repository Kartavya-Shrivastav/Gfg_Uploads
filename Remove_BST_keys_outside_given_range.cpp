
class Solution {
    public:
    
    struct Node{
        int data;
        Node* left;
        Node* right;
    };
    
    Node* removekeys(Node* root, int l, int r) {
        if (!root) {
            return root;
        }
        if (root->data > r) {
            Node *remainingPart = root->left;
            root->left = NULL;
            return removekeys(remainingPart, l, r);
        }
        else if (root->data < l) {
            Node *remainingPart = root->right;
            root->right = NULL;
            return removekeys(remainingPart, l, r);
        }
        else {
            root->left = removekeys(root->left, l, r);
            root->right = removekeys(root->right, l, r);
            return root;
        }
    }
};