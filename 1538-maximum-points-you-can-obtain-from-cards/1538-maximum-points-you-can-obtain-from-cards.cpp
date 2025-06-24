class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n  = cardPoints.size();
        int windowsize = n-k;

        int total = accumulate(cardPoints.begin(),cardPoints.end(),0);

        if(k==n) return total;

        int currsum = 0 ;
         for ( int i =0;i<windowsize;i++){
            currsum+=cardPoints[i];
         }

         int minsum = currsum;

         for(int i = windowsize; i <n ; i++){
            currsum += cardPoints[i] - cardPoints[i-windowsize];
            minsum = min(minsum,currsum);
         }
         return total-minsum;
    }
};