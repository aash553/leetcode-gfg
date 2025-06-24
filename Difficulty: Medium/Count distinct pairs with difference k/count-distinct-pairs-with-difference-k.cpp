class Solution {
  public:
    int TotalPairs(vector<int> nums, int k) {
        unordered_map<int,int>freq;
        int cnt = 0 ;
        
        for(int num : nums){
            freq[num]++;
        }
        
        if(k==0){
        for(auto &p : freq){
            if(p.second>1)
            cnt++;
        }
        }
        
        else{
            for(auto &p : freq){
                if(freq.count(p.first-k))
                cnt++;
            }
        }
        return cnt;
    }
};