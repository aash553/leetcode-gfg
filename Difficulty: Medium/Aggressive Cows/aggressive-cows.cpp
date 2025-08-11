class Solution {
  public:
  
  
   bool ismaxi(vector<int> &stalls, int k, int mid){
    int cowcnt = 1;
    int lastpos = stalls[0];
    
    for(int i =0;i<stalls.size();i++){
        if(mid<=stalls[i]-lastpos){
            cowcnt++;
            if(cowcnt == k ){
                return true;
            }
            lastpos = stalls[i];
        }
    }
    return false;
   }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int s = 0;
        int ans = 0;
        int maxi = INT_MIN;
        for(int i =0;i<n;i++){
            maxi= max(maxi,stalls[i]);
        }
        int e = maxi;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            if(ismaxi(stalls,k,mid)){
                ans = mid;
                s = mid + 1 ;
            }
            else{
                e = mid -1;
            }
        }
        return ans;
    }
};