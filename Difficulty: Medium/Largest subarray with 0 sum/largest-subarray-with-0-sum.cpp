class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        unordered_map<int,int>mpp;
        int sum = 0;
        for (int i = 0 ;i<n;i++){
            sum += arr[i];
            if(sum == 0){
                maxi = i + 1;
            }else{
                if(mpp.find(sum) != mpp.end()){
                    maxi = max(maxi , i-mpp[sum]);
                }else{
                    mpp[sum] = i;
                }
            }
        }
        return maxi;
    }
};