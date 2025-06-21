class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int ans = abs(n/3);

        int cnt  = 0;

        unordered_map<int,int>func;
        for(int i =0;i<n;i++){
            int num = nums[i];
            func[num]++;
        }

        vector<int>result;

        for(auto it : func){
            if(it.second>ans){
                result.push_back(it.first);
            }
        }

        return result;




    }
};