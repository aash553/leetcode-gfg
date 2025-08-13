#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        // Step 1: Count frequencies
        map<int, int> mpp; // keeps numbers in ascending order
        for (auto it : arr) {
            mpp[it]++;
        }

        // Step 2: Transfer to a vector for custom sorting
        vector<pair<int, int>> freqArr; // {num, freq}
        for (auto &p : mpp) {
            freqArr.push_back({p.first, p.second});
        }

        // Step 3: Sort by frequency (desc), then value (asc)
        sort(freqArr.begin(), freqArr.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.second == b.second)
                return a.first < b.first; // smaller number first
            return a.second > b.second;   // higher freq first
        });

        // Step 4: Output sorted by frequency
        vector<int> ans;
        for (auto &p : freqArr) {
            for (int i = 0; i < p.second; i++) {
                ans.push_back(p.first);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
