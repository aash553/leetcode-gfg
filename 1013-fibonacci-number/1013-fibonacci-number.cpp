class Solution {
public:

    int helper(int n ){
        if(n==0)return 0;
        if(n==1) return 1;
        int fibo = helper(n-1)+helper(n-2);
        return fibo;
    }
    
    int fib(int n) {
       return helper(n);
    }
};