class Solution {
  public:
  
  int getsum(vector<int>& arr, int d) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += (arr[i] + d - 1) / d;  
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& arr, int k) {
        int s = 1;
        int maxi = INT_MIN;
        int ans = -1;
        for ( int i=0;i<arr.size();i++){
            maxi = max(maxi,arr[i]);
        }
        int e = maxi;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            
            if(getsum(arr,mid) <= k){
                ans = mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};
