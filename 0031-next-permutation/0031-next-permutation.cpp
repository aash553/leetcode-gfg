class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        int n = nums.size();
        //finding the break point
        for(int i = n-2 ;i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        //if no breakpoint 
        if(index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //once the breakpoint is founded
        for(int i=n-1;i>index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1, nums.end());
    }
};