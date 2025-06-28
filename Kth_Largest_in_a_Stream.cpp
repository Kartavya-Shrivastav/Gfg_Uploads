class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                res.push_back(pq.top());
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
};