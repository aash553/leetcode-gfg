class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int maxi = INT_MIN;
        int lsum =0;
        int rsum= 0;
        for(int i =0;i<k;i++){
            lsum += cardPoints[i];
           maxi=lsum;
        }

        int rightindex = n-1;

        for(int i = k-1 ;i >= 0 ;i--){
            lsum -= cardPoints[i];
            rsum += cardPoints[rightindex];
            rightindex--;
            maxi = max(maxi,lsum+rsum);
        }
        return maxi;
    }
};