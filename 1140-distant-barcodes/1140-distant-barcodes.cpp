class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        unordered_map<int,int>freq; // first->element second->freq;

        for(auto x : barcodes){ // we got the frequencies
            freq[x]++;
        }
        vector<pair<int,int>>freqsort;
        for(auto it : freq){
            freqsort.push_back(it);
        }

        sort(freqsort.begin(),freqsort.end(),[](auto &a, auto &b){
            return a.second>b.second;
        });

        vector<int>result(n);

        int index = 0 ;
        for(auto it : freqsort){
            int barcode = it .first;
            int count  = it . second;

            while(count > 0){
                result[index] = barcode;
                index += 2;

                if(index >= n ) index = 1;
                count --;
            }
        }
        return result;
    }
};