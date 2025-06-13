class Solution {
  public:
    int circularSubarraySum(vector<int> &arr) {
        

        int curr_max=arr[0];
        int curr_min = arr[0];
        int maxi = arr[0];
        int mini = arr[0];
        int totalsum = arr[0];
        int n = arr.size();
        
        for ( int i =1;i<n;i++){
           totalsum+=arr[i]; 
           
           
            curr_max = max(arr[i],curr_max+arr[i]);
            maxi = max(maxi,curr_max);
            
            curr_min = min(arr[i],curr_min+arr[i]);
            mini = min(mini,curr_min);

        }
        if(maxi<0) return maxi;
        
        if (mini == totalsum) return maxi;
        
        return max(maxi, totalsum-mini);
        
        
    }
};