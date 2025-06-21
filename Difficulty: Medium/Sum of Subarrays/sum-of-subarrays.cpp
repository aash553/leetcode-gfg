// User function template for C++

class Solution {
  public:
    long long subarraySum(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9+7;
        long long  ans = 0;
        for(int i =0;i<n;i++){
            long long left = i+1;
            long long  right  = n-i;
            long long contri = (arr[i]%mod * left%mod * right%mod)%mod;
            ans = (ans+contri)%mod;
        }
        return ans;
    }
};