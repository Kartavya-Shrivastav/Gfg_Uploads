// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        set<int>resultSet;
        for (int num : a) {
            resultSet.insert(num); }
        
       for (int num : b) {
            resultSet.insert(num); }
        
        return resultSet.size();
    }
};