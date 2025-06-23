
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int ans = 0;
        int st = 0 ;
         int end = arr.size()-1;
         
         while(st<=end){
         int curr = arr[st]+arr[end];
         if(curr>target){
             end--;
         }else if (curr<target){
             st++;
         }else{
         
         int ele1=arr[st] , ele2 = arr[end] , cnt1= 0 , cnt2=0 ;
         
         while(st<=end && arr[st]==ele1){
             st++;
             cnt1++;
         }
         
         while(st<=end && arr[end]==ele2){
             end--;
             cnt2++;
         }
         
         if(ele1==ele2){
             ans += (cnt1*(cnt1-1))/2;
         }
         
         else{
             ans+=cnt1*cnt2;
         }
             
         }
             
         }
         return ans;
         
    }
};