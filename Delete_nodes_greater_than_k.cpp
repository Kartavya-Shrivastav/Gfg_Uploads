class Solution {
  public:
    Node* deleteNode(Node* root, int k) {
        if( root == NULL ) return NULL ;
        if( root ->data >= k ) return deleteNode( root ->left , k );
        root ->right = deleteNode( root ->right , k );
        return root ;
    }
};