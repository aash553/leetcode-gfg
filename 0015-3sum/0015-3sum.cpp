class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //first we will sort the given array and also keep i as constant
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n;i++){
            //also we know that if the i == i +1 then we must continue till we find a differnt value for it ot avoid duplication
            if(i>0 && nums[i] == nums[i-1])continue;
            int j = i+1;
            int k = n-1;
            // we move till j<k 
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0){
                    j++;
                }else if(sum > 0){
                    k--;
                }else{
                    vector<int>temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //once we move j++ and k-- after every iteration we must make sure its not equal to their previous value so we move them until we find a different value for them to avoid duplication of triplets and make sure j<k
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};