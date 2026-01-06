class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = accumulate(arr.begin(),arr.begin()+k,0);
        int maxSum = sum;
        for(int i = k; i < arr.size(); i++){
            sum += arr[i] - arr[i-k];
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};