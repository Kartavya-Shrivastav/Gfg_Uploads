class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        vector<int> v;
        for(auto it:a){
            v.push_back(it);
        }
        for(auto it:b){
            v.push_back(it);
        }
        sort(v.begin(),v.end());

        int n = v.size();
        return n%2!=0?v[(n)/2]:(v[n/2]+v[(n/2)-1])/2.0;
    }
};