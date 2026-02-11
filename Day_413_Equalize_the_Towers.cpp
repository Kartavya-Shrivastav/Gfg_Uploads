class Solution {
  public:
    virtual int fun(int h, vector<int>& heights, vector<int>& cost){
      int sum=0;
      int i=0;
      for(int x: heights){
        sum += ((abs(x-h))*cost[i]);
        i++;
      }
      
      return sum;
    }
    
    virtual int minCost(vector<int>& heights, vector<int>& cost) {
      int e=INT_MIN, s=INT_MAX;
      
      for(int &x: heights){
        e = max(e, x);  
        s = min(s, x);  
      }
      
      int ans=INT_MAX;

      while(s<=e){
        int m=s+(e-s)/2;
        
        int p=fun(m-1, heights, cost);
        int c=fun(m, heights, cost);
        int n=fun(m+1, heights, cost);
        
        if(c<=p && c<=n){
          ans=c;
          return ans;
        }
        if(c>p && c<=n) e=m-1;
        else s=m+1;
      }
      
      return ans;
    }
};