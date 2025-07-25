#include <bits/stdc++.h>
using namespace std;

// Function to print leaf nodes from the preorder traversal of a BST
// Given a preorder traversal of a BST, this function returns the leaf nodes.

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        vector<int> ans;
        stack<int> st;
        
        st.push(preorder[0]);
        for(int i=1; i<preorder.size(); i++){
            if(preorder[i] < st.top()){
                st.push(preorder[i]);
            }else{
                int temp = st.top();
                int cnt = 0;
                while(!st.empty() && preorder[i] > st.top()){
                    st.pop();
                    cnt++;
                }
                st.push(preorder[i]);
                if(cnt>=2){
                    ans.push_back(temp);
                }
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};