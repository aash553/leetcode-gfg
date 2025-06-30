class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size();
        long long totalsum = 0;
            totalsum = 1LL*(n+1)*(n+2)/2;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        int diff = totalsum-sum;
        return diff;
    }
};