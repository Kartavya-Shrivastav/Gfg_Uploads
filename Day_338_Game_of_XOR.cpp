class Solution {
  public:
    int xorOfiFunc(int num, int cnt){
        if((cnt % 2) == 0){
            return 0;
        } else{
            return num;
        }
    }
  
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int cnt = (i*(n-i)) + (n-i);
            int xorOfi = xorOfiFunc(arr[i], cnt);
            ans = ans ^ xorOfi;
        }
        
        return ans;
    }
};