class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;

        int row0 = 0;
        int row1 = matrix.size() - 1;
        int col0 = 0;
        int col1 = matrix[0].size() - 1;

        while(row0 <= row1 && col0 <= col1) {

            for(int i = col0; i <= col1; i++) {
                order.push_back(matrix[row0][i]);
            }
            row0++;

            for(int i = row0; i <= row1; i++) {
                order.push_back(matrix[i][col1]);
            }
            col1--;

            if(row0 <= row1) {
                for(int i = col1; i >= col0; i--) {
                    order.push_back(matrix[row1][i]);
                }
                row1--;
            }

            if(col0 <= col1) {
                for(int i = row1; i >= row0; i--) {
                    order.push_back(matrix[i][col0]);
                }
                col0++;
            }
        }

        return order;
    }
};