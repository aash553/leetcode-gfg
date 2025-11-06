class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>prefix;
        prefix[0] = 1 ;
        int sum = 0;
        int cnt = 0;
        for(int i = 0 ;i<nums.size();i++){
            sum += nums[i];
        int rem = sum % k;
        if(rem < 0) rem += k; // handles negative 
        if(prefix.find(rem) != prefix.end()){
            cnt += prefix[rem];
        }
            prefix[rem]++;
        }
        return cnt;
    }
};