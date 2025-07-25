class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>seen;
        int n = nums.size();
        int sum =0;

        int negnum = INT_MIN;

        for( auto & num : nums){
            if(num<=0){
                negnum = max(num,negnum);
            }else if(!seen.count(num)){
                sum += num;
                seen.insert(num);
            }
        }
        return sum == 0 ? negnum : sum;
    }
};