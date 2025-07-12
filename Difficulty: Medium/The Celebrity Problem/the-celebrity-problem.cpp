class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        while (top < down) {
            if (mat[top][down] == 1) {
               
                top++;
            } else {
                
                down--;
            }
        }

        // Verify if top is actually a celebrity
        for (int i = 0; i < n; i++) {
            if (i == top) continue;

            
            if (mat[top][i] == 1 || mat[i][top] == 0)
                return -1;
        }

        return top;
    }
};
