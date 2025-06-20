// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0 ;
         for( int i=0;i<n;i++){
             if(arr[i]<=k)
             cnt++;
         }
         
         int bad = 0;
         for ( int i =0;i<cnt;i++){
             if(arr[i]>k){
                 bad++;
             }
         }
         
         int ans = bad;
         
         for(int i=0,j=cnt;j<n;i++,j++){
             if(arr[i]>k)
                 bad--;
                 
             if(arr[j]>k)
             bad++;
             
             ans = min(ans,bad);
         }
         return ans;
    }
};
