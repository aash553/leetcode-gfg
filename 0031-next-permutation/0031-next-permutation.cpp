class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        //find the break point 
        int n=nums.size();
        int ind = -1;
        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }

        //if there is no break point reverse the whole array 

        if(ind == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        //after finding the breakpoint find the next element which is just bigger than ind element

        for(int i=n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        // after that reverse the whole 

        reverse(nums.begin()+ind+1, nums.end());
    }
};