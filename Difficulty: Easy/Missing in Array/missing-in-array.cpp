class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long  sum = 1LL*(n+1)*(n+2)/2;
        long long  actualsum  = 0;
    for ( int i =0;i<n;i++){
        actualsum+=arr[i];
    }
    return (int)(sum-actualsum);
    }
};