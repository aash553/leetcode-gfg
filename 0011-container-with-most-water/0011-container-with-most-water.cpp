class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l =0;
        int r = n-1;
        int maxwater = 0;
        int currwater = 0;

        while(l<r){
            int w = r-l;
            int ht = min(height[l], height[r]);
            currwater = w * ht;
            maxwater = max(maxwater , currwater);

            if(height[l]<height[r] ? l++ : r--);
        }
        return maxwater;
    }
};