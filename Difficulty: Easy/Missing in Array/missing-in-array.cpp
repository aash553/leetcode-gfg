class Solution {
  public:
    int missingNum(vector<int>& arr) {
        long long fullsum = 0 ;
        int n = arr.size();

        fullsum = 1LL*(n+1)*(n+2)/2;
        
        long long sum = 0;
        for (int i =0;i<arr.size();i++){
            sum+=arr[i];
        }
        int diff= fullsum-sum;
        return diff;
    }
};