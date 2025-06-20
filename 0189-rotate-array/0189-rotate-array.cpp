class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<=1) return ;

        vector<int>temp(n);
        for(int i =0;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }

        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
    }
};