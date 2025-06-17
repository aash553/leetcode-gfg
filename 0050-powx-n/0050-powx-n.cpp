class Solution {
public:
    double myPow(double x, int n) {
        long bino = n;
        double ans = 1;

        if(n<0){
            x=1/x;
            bino = -bino;
        }

        while(bino>0){
            if(bino%2==1){
                ans*=x;
            }
            x*=x;
            bino/=2;
        }
        return ans;
    }
};