class Solution {
  public:
    int rec(int ind,vector <vector <int>> &cost,int mask,vector <vector <int>> &dp){
        int n=cost.size();
        mask=mask^(1<<ind);
        if(mask==0) return cost[ind][0];
        
        if(dp[ind][mask]!=-1)   return dp[ind][mask];
        
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            if(mask&(1<<j)){
                ans=min(ans,cost[ind][j]+rec(j,cost,mask,dp));
            }
        }
        
        return dp[ind][mask]=ans;
    }
    
    int tsp(vector<vector<int>>cost){
        int n=cost.size();
        int mask=pow(2,n)-1;
        vector <vector<int>> dp(n,vector <int> (mask+1,-1));
        return rec(0,cost,mask,dp);
    }
};