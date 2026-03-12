// User function template for C++
class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        int best_sum =-1 , best_len =0 , best_start = -1;
        int curr_sum = 0 , curr_start = 0, curr_len = 0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(arr[i] >= 0){
                curr_sum += arr[i];
                curr_len++;
            }
            else{
                if(curr_len > 0){
                    if(curr_sum > best_sum || curr_sum == best_sum && curr_len > best_len){
                        best_sum = curr_sum;
                        best_start = curr_start;
                        best_len = curr_len;
                    }
                }
            curr_sum = 0;
            curr_start = i+1;
            curr_len =0;
            }
        }
            //final blocl check
            if(curr_len >0){
                 if(curr_sum > best_sum || curr_sum == best_sum && curr_len > best_len){
                        best_sum = curr_sum;
                        best_start = curr_start;
                        best_len = curr_len;
                 }
            }
        if(best_sum == -1) return {-1};
        for(int i = best_start ; i<best_start+best_len;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};