class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n=(int)arr.size();
        vector<int>prefixOdd(n+1,0);
        vector<int>prefixEven(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            prefixOdd[i] = prefixOdd[i-1];
            prefixEven[i] = prefixEven[i-1];
            
            if((i-1)%2)
            {
                prefixOdd[i]+=arr[i-1];
            }
            else
            {
                prefixEven[i]+=arr[i-1];
            }
        }
        
        int count =0;
        for(int i=0;i<n;i++)
        {
            int sumOdd = prefixOdd[i];
            int sumEven = prefixEven[i];
            
            
            sumEven+=prefixOdd[n] - prefixOdd[i+1];
            sumOdd+=prefixEven[n] - prefixEven[i+1];
            
            if(sumOdd == sumEven)
            count++;
        }
        return count ;
    }
};