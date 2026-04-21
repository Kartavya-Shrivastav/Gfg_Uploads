class Solution {
  public:
    virtual int fun(int i, int n, int k, int col, int count, vector<vector<int>> &dp){
      if(i>n) return 1;
      if(dp[i][count] != -1) return dp[i][count];
      
      int ans=0;
      for(int j=1; j<=k; j++){
        if(col==j && count==2) continue;  
        if(col==j && count==1) ans+=fun(i+1, n, k, j, 2, dp);
        else ans+=fun(i+1, n, k, j, 1, dp);
      }
      return dp[i][count]=ans;
    }
    
    virtual int countWays(int n, int k){
      vector<vector<int>> dp(n+1, vector<int>(3, -1));
      return fun(1, n, k, 0, 0, dp);
    }
};