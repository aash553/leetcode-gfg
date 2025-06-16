// User function Template for C++

class Solution {
  public:
  
  bool ispossible(vector<int> & stalls, int k , int mid  ){
      int cowcnt = 1; 
      int lastpow  = stalls[0];
      
      for(int i =0;i<stalls.size();i++){
          if(stalls[i]-lastpow>=mid){
             cowcnt++;
             if(cowcnt==k){
                 return true ;
             }
             lastpow= stalls[i];
          }
      }
      return false;
  }

    int aggressiveCows(vector<int> &stalls, int k) {

      sort(stalls.begin(),stalls.end());
      
      int s = 0;
      int maxi = -1;
      for(int i=0;i<stalls.size();i++){
          maxi = max(maxi,stalls[i]);
      }
      int e = maxi;
      int ans = -1;
      while(s<=e){
          int mid = s+(e-s)/2;
          if(ispossible(stalls,k,mid)){
              ans = mid;
              s = mid+1;
          }else{
              e = mid-1;
          }
      }
      return ans;
    }
};