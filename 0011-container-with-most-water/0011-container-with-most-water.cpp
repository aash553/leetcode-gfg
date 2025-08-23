class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int curwater = 0;
        int maxwater = 0;
        while(l<r){
            int wd = r-l;
            int ht = min(height[l],height[r]);
            curwater = wd*ht;
            maxwater = max(maxwater ,curwater);
            if(height[l]<height[r] ? l++ : r--);
        }
        return maxwater;
    }
};