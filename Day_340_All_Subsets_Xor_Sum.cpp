class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        int n=arr.size();
        int s=0;
        for(auto it:arr){
            s|=it;
        }
        return s*pow(2,n-1);
    }
};