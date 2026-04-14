class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<k;i++){
            sum += arr[i];
        }
        maxi = sum;
        for(int i = k;i<n;i++){
            sum += arr[i];
            sum -= arr[i-k];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};