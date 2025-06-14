// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int cnt = 0 ;
        for (auto x : arr){
            if(x<=k)cnt++;
        }
        int bad = 0;
        for(int i=0;i<cnt;i++){
            if(arr[i]>k){
                bad++;
            }
        }
        
        int ans = bad;
        
        for(int i=0, j=cnt;j<arr.size();i++,j++){
            if(arr[i]>k)bad--; // adding the bad element
            if(arr[j]>k)bad++;
            ans = min(ans,bad);
        }
        return ans;
    }
};
