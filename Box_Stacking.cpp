class Solution {
  public:
    int maxHeight(vector<int> &height, vector<int> &width, vector<int> &length) {
        // Your code here
        int n = height.size();
        vector<vector<int>> arr;
        
        for (int i = 0; i < n; ++i){
            vector<int> per = {height[i], width[i], length[i]};
            sort(per.begin(), per.end());
            
            do {
                arr.push_back(per);
            } while (next_permutation(per.begin(), per.end()));
        }
        
        sort(arr.begin(), arr.end(), [](vector<int> a, vector<int> b) {
          return a[0] * a[1] > b[0] * b[1]; 
        });
        
        n = arr.size();
        vector<int> dp(n);
        
        for (int i = 0; i < n; ++i){
            dp[i] = arr[i][2];
            for (int j = 0; j < i; ++j){
                if (arr[j][0] > arr[i][0] && arr[j][1] > arr[i][1]) {
                    dp[i] = max(dp[i], dp[j] + arr[i][2]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};