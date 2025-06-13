class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0)) return false;
        int revNum =0;
        while (x>revNum){
        int lastdigit = x % 10;
        revNum = (revNum*10)+lastdigit;
        x/=10;
        }
        return (x==revNum || x==revNum/10);
    }
};