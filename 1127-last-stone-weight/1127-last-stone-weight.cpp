class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
         priority_queue<int> maxHeap(stones.begin(), stones.end());

        while (maxHeap.size() > 1) {
            int stone1 = maxHeap.top(); maxHeap.pop(); // heaviest
            int stone2 = maxHeap.top(); maxHeap.pop(); // second heaviest

            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
            // If stone1 == stone2, both are destroyed, do nothing
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};