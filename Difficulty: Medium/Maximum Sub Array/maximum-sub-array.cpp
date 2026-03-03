class Solution {
  public:
    vector<int> findSubarray(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> ans;

        int curr_sum = 0;
        int curr_start = 0;
        int best_sum = -1;
        int curr_len = 0, best_len = 0;
        int best_start = -1;

        for(int i = 0; i < n; i++) {

            if(arr[i] >= 0) {
                curr_sum += arr[i];
                curr_len++;
            }
            else {
                if(curr_len > 0){
                    
                if(curr_sum > best_sum) {
                    best_sum = curr_sum;
                    best_len = curr_len;
                    best_start = curr_start;
                }
                else if(curr_sum == best_sum) {
                    if(curr_len > best_len) {
                        best_len = curr_len;
                        best_start = curr_start;
                    }
                }
                }
                curr_sum = 0;
                curr_len = 0;
                curr_start = i + 1;
            }
        }

        // FINAL comparison for last block
        if(curr_len > 0){
        if(curr_sum > best_sum) {
            best_sum = curr_sum;
            best_len = curr_len;
            best_start = curr_start;
        }
        else if(curr_sum == best_sum) {
            if(curr_len > best_len) {
                best_len = curr_len;
                best_start = curr_start;
            }
        }
   }

        if(best_sum == -1) return {-1};

        for(int i = best_start; i < best_start + best_len; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};