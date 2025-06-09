class Solution {
public:

    int countpair(vector<int>&nums , int mid ){
        int count=0;
        int j=0;
        for ( int i =0;i<nums.size();i++){
            while(j<nums.size() && nums[j]-nums[i]<=mid){
                j++;
            }
            count+=(j-i-1);
        }
        return count;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort (nums.begin(), nums.end());
        int s = 0 ;
        int e = nums.back() - nums.front();
        while(s<e){
            int mid = s+(e-s)/2;
            int cnt = countpair(nums,mid);
            if(cnt<k){
                s = mid + 1;
            }
            else{
                e= mid ;
            }
        }
        return s;
    }
};