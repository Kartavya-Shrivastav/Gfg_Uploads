//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
public:
    pair<int,int> a(Node *root)
    {
        if(root == NULL)
        {
            return {0,0};
        }
        
        pair<int,int> l = a(root->left);
        pair<int,int> r = a(root->right);
        
        int in = root->data + l.second + r.second;
        int ex = max(l.first,l.second) + max(r.first,r.second);
        
        return {in,ex};
        
    }
    int getMaxSum(Node *root)
    {
        // Add your code here
        pair<int,int> akshu = a(root);
        return max(akshu.first,akshu.second);
    }
};