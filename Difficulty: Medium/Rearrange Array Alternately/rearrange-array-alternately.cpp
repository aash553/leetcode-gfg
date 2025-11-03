class Solution {
  public:
    void rearrange(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int>ans;
        int i = 0 , j = n-1;
        for(int k = 0 ; k<n ; k++){
            if(k % 2 == 0)
                ans.push_back(arr[j--]);
            else
                ans.push_back(arr[i++]);
        }
        
        for(int k =0 ; k < n ; k++){
            arr[k] = ans[k];
        }
    }
};