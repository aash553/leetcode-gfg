class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int xr = 0;
        unordered_map<int,int>mpp;
        
        mpp[0]=1;
        for(int i =0 ;i<n;i++){
            xr = xr ^ arr[i];
            int x = xr ^ k;
            
            if(mpp.find(x) != mpp.end()){
                cnt += mpp[x];
            }
            mpp[xr]++;
        }
        return cnt;
    }
};