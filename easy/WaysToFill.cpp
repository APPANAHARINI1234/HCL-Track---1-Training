#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#include<string>
/*
 * Complete the 'countInstallationSequences' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER n as parameter.
 */

long long  returnways(int n, vector<long long>&dp){
    if(n == 0)
      return 1l;
    if(n < 0)
     return 0;
     if(dp[n] != -1)
       return dp[n];
    return dp[n] = returnways(n - 1, dp) + returnways(n - 2, dp);
}
string countInstallationSequences(int n) {
    string s = "";
    vector<long long>dp(n + 1, -1);
    long long ans = returnways(n, dp);
   // cout << ans<<endl;
    return to_string(ans);
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string result = countInstallationSequences(n);

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
