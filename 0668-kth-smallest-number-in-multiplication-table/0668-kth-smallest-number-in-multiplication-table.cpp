class Solution {
public:


    int issmall(int m , int n , int k ,int mid){
        int cnt = 0;
        for ( int i=1;i<=m;i++){
            cnt+=min(mid/i,n);
        }
        return cnt>=k;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 0;
        int high = m*n;
        while(low<high){
            int mid = low+(high-low)/2;
            if(issmall(m,n,k,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};