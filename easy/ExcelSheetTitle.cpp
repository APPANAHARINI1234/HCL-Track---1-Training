class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        while (columnNumber > 0) {
            int col = columnNumber % 26;
            if (col == 0) {
                ans.push_back('Z');
                columnNumber--;
            } else {
                ans.push_back('A' + col - 1);
            }
            columnNumber /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};