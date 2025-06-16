class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
        int n = heights.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&heights](const int &a, const int &b) {
           return heights[a] < heights[b]; 
        });
        
        long long sufCost = 0, sufProdSum = 0;
        for(int i = 0; i < n; i++) {
            sufCost += cost[idx[i]];
            sufProdSum += heights[idx[i]] * cost[idx[i]];
        }
        
        long long preCost = 0, preProdSum = 0;
        long long ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            preCost += cost[idx[i]];
            preProdSum += heights[idx[i]] * cost[idx[i]];
            sufCost -= cost[idx[i]];
            sufProdSum -= heights[idx[i]] * cost[idx[i]];
            long long totalCost = (heights[idx[i]] * preCost - preProdSum)
                                    + (sufProdSum - heights[idx[i]] * sufCost);
            ans = min(ans, totalCost);
        }
        return ans;
    }
};