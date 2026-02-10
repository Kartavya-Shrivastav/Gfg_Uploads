class Solution {
  public:
    bool isfeasible(int mid,vector<int>&arr,int k){
        if(mid==0){
            return false;
        }
        int count=0;
        for(int i=0;i<arr.size();i++){
            count=count+(arr[i]/mid);
            if(arr[i]%mid){
                count++;
            }
        }
        if(count>k){
            return false;
        }
        return true;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        const int n=arr.size();
        int j=0;
        
        for(int i=0;i<n;i++){
            j=max(j,arr[i]);
        }
        int i=0; 
        while(i<j){
            int mid=i+(j-i)/2;
            
            if(isfeasible(mid,arr,k)){
                j=mid;
            }
            else{
                i=mid+1;
            }
        }
        return j;
    }
};