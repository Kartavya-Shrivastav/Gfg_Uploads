class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int count = 0, flag=0;
        
        for(int i=0; i<n-1; i++){
            count++;
            if(arr[i] > arr[i+1]){
                flag = 1;
                break;
            }   
        }
        
        return flag==1? count: 0;
    }
};