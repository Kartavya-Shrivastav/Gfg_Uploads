class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        int n=a.size();
        sort(a.begin(), a.end());
        
        int mini=1e9;
        
        for(int i=m-1; i<n; i++){
            mini=min(mini, a[i]-a[i-m+1]);
        }
        
        return mini;
    }
};