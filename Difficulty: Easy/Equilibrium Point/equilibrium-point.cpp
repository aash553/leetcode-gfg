class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int total = 0;
        for (int i =0;i<arr.size();i++){
            total+=arr[i];
        }
        int leftsum = 0;
        for(int i =0;i<arr.size();i++){
            total-=arr[i];
        if(total==leftsum)return i;
        leftsum+=arr[i];
        }
        return -1;
    }
};