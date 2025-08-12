class Solution {
public:


    int countpair(vector<int>&nums,int mid , int k){
        int  j =0;
        int count = 0;
        for(int i =1;i<nums.size();i++){
            while(nums[i]-nums[j] > mid){
                j++;
            }
            count += i-j;
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int high = nums[n-1] - nums[0];
        int low = INT_MAX;
        for(int i =1;i<n;i++){
            if(nums[i]-nums[i-1]<low)
            low = nums[i]-nums[i-1];
        }

        while(low<high){
            int mid = low+(high-low)/2;

            int count = countpair(nums,mid,k);
            if(count<k){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};