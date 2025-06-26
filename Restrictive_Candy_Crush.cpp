class Solution {
  public:
    string Reduced_String(int k, string &s) {
        vector<pair<char,int>> st;
        for(auto &i:s){
            if(st.empty() or st.back().first!=i) st.push_back({i,0});
            if(++st.back().second==k) st.pop_back();
        }
        string ans;
        for(auto &i:st){
            ans+=string(i.second,i.first);
        }
        return ans;
    }
};