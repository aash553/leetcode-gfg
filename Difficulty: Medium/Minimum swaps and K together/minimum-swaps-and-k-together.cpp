// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int bad = 0;
        int cnt = 0;
        int ans = 0;
        for ( int i =0;i<n;i++){
            if(arr[i]<=k)
                cnt++;
        }
        
        for(int i = 0 ; i<cnt;i++){
            if(arr[i]>k)
            bad++;
        }
        
        ans = bad;
        
        for(int i =0 , j = cnt ; j<n ; i++,j++){
            if(arr[i]>k)
            bad--;
            
            if(arr[j]>k)
            bad++;
            
            ans = min(ans,bad);
        }
    return ans;
    }
};
