class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //finding the break point 
        int ind = -1;
        int n = nums.size();
        for(int i =n-2 ; i >=0;i--){
            if (nums[i] < nums[i+1] ){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //find the element closest to ind
        for(int i = n-1 ;i>ind ;i--){
            if(nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        //reverse the remaining half
        reverse(nums.begin()+ind+1,nums.end());
    }
};