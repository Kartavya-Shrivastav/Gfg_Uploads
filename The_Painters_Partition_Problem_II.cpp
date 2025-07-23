class Solution {
  public:
    bool ispossible(vector<int>& arr, int k,int mid){
        int s=0;
        for(auto i:arr){
            s+=i;
            if(s>mid){
                k--; s=i;
                if(s>mid)return false;
            }
        }
        return k>0? true:false;
    }
  
    int minTime(vector<int>& arr, int k) {
        int sum=0;
        for(auto i:arr)sum+=i;
        int start=0,end=sum,mid;
        while(start<end){
             mid=(start+end)/2;
            
            if(ispossible(arr,k,mid)){
                end=mid;
            }
            else start=mid+1;
        }
        return end;
    }
};