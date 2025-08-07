// User function Template for C++

class Solution {
  public:
  
  bool isprime(int n ){
      if(n<=1) return false;
      if(n<=3) return true;
      if(n%2 == 0 || n %3 == 0) return false;
      for(int i=5 ;i*i<=n;i+=6){
          if(n%i == 0 || n%(i+2) == 0) return false;
      }
      return true;
  }
  
  
    int prime_Sum(int n) {
        // Code here
        
        int sum=0;
        for(int i =2;i<=n;i++){
            if(isprime(i)){
                sum+=i;
            }
        }
        return sum;
    }
};