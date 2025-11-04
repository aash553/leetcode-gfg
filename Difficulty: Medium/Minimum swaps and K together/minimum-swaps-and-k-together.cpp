// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int ans = 0 ;
        int bad = 0 ;
        int cnt = 0 ;
        
        for(int i = 0 ; i < arr.size(); i++){
            if(arr[i] <= k){
                cnt ++;
            }
        }
        
        for(int i = 0;i<cnt ; i++){
            if(arr[i] > k){
                bad ++;
            }
        }
        ans = bad;
        
        for(int i = 0 ,  j = cnt ; j<arr.size() ; i++ , j++){
            if(arr[i] > k){
                bad--;
            }
            if(arr[j] > k){
                bad ++ ;
            }
            ans = min(ans,bad);
        }
        return ans;
    }
};
