class Solution {
public:
    int fib(int n) {
        int a = 0;
        int b = 1;
        
        for(int i = 1 ; i<n;i++){
            int newnumber = a + b;

            a=b;
            b=newnumber;
        }
        return b;
    }
};