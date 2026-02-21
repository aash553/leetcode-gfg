class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int prev = INT_MIN;
        int maxi = arr[0];
        int n = arr.size();
        for(int i =0 ;i<n;i++){
            if(arr[i] > maxi){
                prev= maxi;
                maxi = arr[i];
            }
            else if(arr[i] > prev && arr[i] < maxi){
                prev = arr[i];
            }
        }
        if(prev == INT_MIN) return -1;
        return prev;
    }
};