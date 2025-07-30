class Solution {
  public:
  
  bool ispossible(vector<int> &stalls, int k, int mid ){
      int cowcount = 1;
      int cowpos = stalls[0];
      
      for(int i =0;i<stalls.size();i++){
          if(stalls[i]-cowpos >= mid ){
              cowcount ++;
              if(cowcount == k){
                  return true;
              }
              cowpos = stalls[i];
          }
      }
      return false;
  }
  
  
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());
        
        int s = 0;
        int maxi = INT_MIN;
        
        for(int i =0;i<stalls.size();i++){
            maxi = max(maxi,stalls[i]);
        }
        
        int e = maxi;
        int ans = 0;
        
        
        while(s<=e){
        int mid = s+(e-s)/2;
            if(ispossible(stalls,k,mid)){
                ans = mid ;
                s = mid + 1;
            }
            else{
                e = mid -1;
            }
        }
        return ans;
    }
};