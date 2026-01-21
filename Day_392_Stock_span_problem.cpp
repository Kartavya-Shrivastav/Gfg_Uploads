class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        vector<int> ans;
        stack<int> st;
        st.push(-1);
        
        for(int i=0; i<arr.size(); i++){
            while(st.top()!=-1 && (arr[st.top()] <= arr[i]))
                st.pop();
            
            ans.push_back(i - st.top());
            st.push(i);
        }
        
        return ans;
    }
};