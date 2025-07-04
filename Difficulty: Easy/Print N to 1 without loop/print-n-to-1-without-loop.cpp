class Solution {
  public:
    void printNos(int N) {
        if(N==0) return ;
            cout << N << " ";
            return printNos(N-1);
    }
};