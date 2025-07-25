
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int st = 0;
        int ans =0;
        int end = arr.size()-1;
        
        while(st<=end){
            int curr = arr[st] + arr[end];
            if(curr>target){
                end--;
            }
            else if(curr<target){
                st++;
            }
            else{
                int ele1 =arr[st] ; int cnt1 =0 ; int ele2=arr[end] ; int cnt2=0;
                
                while(st<=end && arr[st] == ele1){
                    cnt1++;
                    st++;
                }
                
                while(st<=end && arr[end]== ele2){
                    cnt2++;
                    end--;
                }
                if(ele1==ele2){
                    ans += (cnt1*(cnt1-1)/2);
                }
                else{
                    ans += cnt1*cnt2;
                }
            }
        }
        return ans;
    }
};