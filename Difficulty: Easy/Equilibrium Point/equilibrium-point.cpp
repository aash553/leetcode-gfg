class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        int totalsum = 0;
        
        for(int i =0;i<n;i++){
            totalsum += arr[i];
        }
        int leftsum = 0;
        for(int i=0;i<n;i++){
            int rightsum = totalsum - leftsum - arr[i];
            if(leftsum == rightsum) return i;
            leftsum += arr[i];
        }
        return -1;
    }
};