class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int cnt =0;
        for(int num : nums){
            if(freq.count(num-k)) cnt += freq[num-k];
            if(freq.count(num+k)) cnt +=freq[num+k];

            freq[num]++;
        }
        return cnt;
    }
};