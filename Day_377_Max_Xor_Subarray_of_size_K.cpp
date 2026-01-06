class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
      int answer=INT_MIN;
      int first=0;
      int second=0;
      int temp=0;
      
      while(second<arr.size())
      {   
         temp= temp^arr[second];
         
         if(second-first+1 ==k)
         {
            answer = max(temp,answer);
             
             // ab temp me se use hatana padega 
             temp= temp^arr[first];
             first++;
         }
         second++;
          
          
      }
      return answer;
        
    }
};