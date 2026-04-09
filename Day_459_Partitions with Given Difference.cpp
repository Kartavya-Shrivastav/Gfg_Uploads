class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n =  arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++) sum+=arr[i];
        if(diff>sum) return 0;
        if ((sum + diff) % 2 != 0) return 0;

        int s2 = (sum+diff)/2;
        vector<vector<int>> dp(n+1, vector<int>(s2+1));
        for(int i=0; i<=n; i++) dp[i][0]=1;
        //for(int j=  1;j<=s2;j++) dp[0][j]=0;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=s2;j++){
                if(arr[i-1]>j) dp[i][j]= dp[i-1][j];
                 else  dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
                
            }
        }
            return dp[n][s2];
    }
};