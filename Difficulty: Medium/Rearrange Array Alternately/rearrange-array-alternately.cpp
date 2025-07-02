class Solution {
public:
    void rearrange(vector<int>& arr) {
        // First, sort the array
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int maxIndex = n - 1;
        int minIndex = 0;
        int maxEle = arr[n - 1] + 1;
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                // Even index: place max element
                arr[i] += (arr[maxIndex] % maxEle) * maxEle;
                maxIndex--;
            } else {
                // Odd index: place min element
                arr[i] += (arr[minIndex] % maxEle) * maxEle;
                minIndex++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            arr[i] /= maxEle;
        }
    }
};