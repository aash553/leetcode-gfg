class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int maxlen = 0;
        long long sum = 0;
        unordered_map<int,int>prefix;
        for(int i =0;i<n;i++){
            sum += arr[i];
            if(sum == k){
               maxlen =  max(i+1,maxlen);
            }
            int rem = sum-k;
            if(prefix.find(rem) != prefix.end()){
                int len = i-prefix[rem];
                maxlen = max(maxlen ,len);
            }
            if(prefix.find(sum) == prefix.end()){
                prefix[sum] = i;
            }
        }
        return maxlen;
    }
};