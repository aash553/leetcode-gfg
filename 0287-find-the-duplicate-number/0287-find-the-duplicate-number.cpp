class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        //move the pointer to the start and find until they meet again 

        slow = 0;
        while(slow!=fast){
            slow=nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};