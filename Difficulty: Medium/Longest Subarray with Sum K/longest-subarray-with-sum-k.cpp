class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        map<long long, int > prefixsum;
        long long sum = 0;
        int maxlen = 0;
        for( int i =0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                maxlen = max(maxlen,i+1);
            }
            int rem = sum - k;
            if(prefixsum.find(rem)!=prefixsum.end()){
                int len = i - prefixsum[rem];
                maxlen = max(maxlen,len);
            }
            if(prefixsum.find(sum)==prefixsum.end()){
                prefixsum[sum]=i;
            }
        }
        return maxlen;
    }
};