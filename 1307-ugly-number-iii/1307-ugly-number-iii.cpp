class Solution {
public:

    long long gcd(long long x , long long y){
        return (y==0) ? x : gcd(y,x % y);
    }

    long long lcm (long long x , long long y){
        return x/gcd(x,y) * y;
    }

    int nthUglyNumber(int n, int a, int b, int c) {
        long long ab = lcm(a,b);
        long long bc = lcm(b,c);
        long long ac = lcm(a,c);
        long long abc =lcm(ab,c);

        long long low = 0 ;
        long long high = 2e18;
        while(low<high){
            long long mid = low + (high-low)/2;
            long long count = (mid/a) + (mid/b) + (mid)/c -
                            (mid/ab) - (mid/bc) - (mid/ac)+
                            (mid/abc);
        if(count >=n){
            high = mid;
        }
        else{
            low = mid+1;
        }
        }
        return low;
    }
};