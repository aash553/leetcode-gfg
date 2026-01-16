// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int k = 1;
        int n = arr.size();
        vector<int>temp(n,0);
        for(int i = 0 ;i<n;i++){
            temp[(i+k)%n] = arr[i];
        }
        
        for(int i = 0 ;i<n;i++){
            arr[i] = temp[i];
        }
    }
};