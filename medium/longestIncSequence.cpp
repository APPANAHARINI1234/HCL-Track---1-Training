#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'computeLongestIncreasingSubsequenceLength' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY quality
 */
int longestIncSeq(vector<int>nums, int prev, int curr, vector<vector<int>>&dp){
   // cout << prev<<" "<<curr<<" "<<nums.size()<<dp.size()<< " "<<endl;
    if(curr >= nums.size() + 1)
      return 0;
      int maxi = 0;
      if(dp[prev][curr] != -1){
        return dp[prev][curr];
      }
    if(prev == 0 || nums[curr - 1] > nums[prev - 1]){
       
        maxi = 1 + longestIncSeq(nums, curr , curr + 1, dp);
    }
    maxi = max(maxi, longestIncSeq(nums, prev, curr + 1,  dp));
    return dp[prev][curr] = maxi;
}
int computeLongestIncreasingSubsequenceLength(int n, vector<int> quality) {
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
    
    return longestIncSeq(quality, 0, 1, dp);
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string quality_count_temp;
    getline(cin, quality_count_temp);

    int quality_count = stoi(ltrim(rtrim(quality_count_temp)));

    vector<int> quality(quality_count);

    for (int i = 0; i < quality_count; i++) {
        string quality_item_temp;
        getline(cin, quality_item_temp);

        int quality_item = stoi(ltrim(rtrim(quality_item_temp)));

        quality[i] = quality_item;
    }

    int result = computeLongestIncreasingSubsequenceLength(n, quality);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
