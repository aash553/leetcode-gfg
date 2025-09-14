class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int maxlen = 0;
        long long sum = 0;
        unordered_map<int,int>prefixsum;
        for(int i =0;i<arr.size();i++){
            sum += arr[i];
            if(sum == k){
                maxlen = max(maxlen,i+1);
            }
            int rem = sum -k;
            if(prefixsum.find(rem) != prefixsum.end()){
                int len = i - prefixsum[rem];
                maxlen = max(maxlen,len);
            }
            if(prefixsum.find(sum) == prefixsum.end()){
                prefixsum[sum] = i;
            }
        }
        return maxlen;
    }
};