// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        // code here
        map<int,int>mpp;
        mpp[0]=1;
        int prefixsum = 0;
        int cnt = 0;
        for ( int i =0;i<arr.size();i++){
            prefixsum +=arr[i];
            int rem = prefixsum-k;
            cnt += mpp[rem];
            mpp[prefixsum]+=1;
        }
        return cnt;
    }
};