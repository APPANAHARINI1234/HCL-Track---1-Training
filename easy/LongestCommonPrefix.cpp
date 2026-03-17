class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonprefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            string temp = "";
            for (int j = 0; j < min(strs[i].size(), commonprefix.size()); j++) {
                if (strs[i][j] != commonprefix[j]) break;
                temp.push_back(strs[i][j]);
            }
            commonprefix = temp;
        }
        return commonprefix;
    }
};