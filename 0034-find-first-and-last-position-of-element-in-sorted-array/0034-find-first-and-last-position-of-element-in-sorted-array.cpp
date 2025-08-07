class Solution {
public:

    int findfirst(vector<int>& nums, int target){

        int n = nums.size();

        int s= 0;
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                e = mid - 1 ; // keep searching on the left 
            }
            else if(nums[mid] < target){
                s= mid+1;
            }
            else{
                e = mid -1;
            }
        }
        return ans;
    }


    int findlast(vector<int>& nums, int target){
         int n = nums.size();

        int s= 0;
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid] == target){
                ans = mid;
                s = mid + 1; // keep searching in the right
            }else if(nums[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid -1;
            }
        } 
        return ans;
    }



    vector<int> searchRange(vector<int>& nums, int target) {
        int first= findfirst(nums,target);
        int last = findlast(nums,target);
        return {first,last};
    }
};