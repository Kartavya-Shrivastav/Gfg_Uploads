class Solution {
  public:
    int hIndex(vector<int>& arr) {
        int ans=0;
        for(int i=1; i<=arr.size(); i++){
            int count=0;
            for(int x: arr){
                if(x >= i) count++;
            }
            
            if(count >= i) ans++;
        }

        return ans;
    }
};