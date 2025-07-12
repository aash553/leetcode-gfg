class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long totalsum = 0;
        int n = arr.size();
        totalsum += 1LL * (n+1)*(n+2)/2;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        return (totalsum-sum);
    }
};