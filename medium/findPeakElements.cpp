#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findPeakIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY counts as parameter.
 */

int findPeakIndex(vector<int> counts) {
    if(counts[1] < counts[0])
      return 0;
    if(counts[counts.size() - 1] > counts[counts.size() - 1])
      return counts.size() - 1;
      int low = 1;
      int high = counts.size() - 2;
      while(low <= high){
        int mid = low + (high - low)/2;
        if(counts[mid - 1] < counts[mid] && counts[mid] > counts[mid + 1])
          return mid;
        if(counts[mid - 1] > counts[mid])
          high = mid - 1;
        else
         low = mid + 1;
      }
      return -1;
}

int main()
{
    string counts_count_temp;
    getline(cin, counts_count_temp);

    int counts_count = stoi(ltrim(rtrim(counts_count_temp)));

    vector<int> counts(counts_count);

    for (int i = 0; i < counts_count; i++) {
        string counts_item_temp;
        getline(cin, counts_item_temp);

        int counts_item = stoi(ltrim(rtrim(counts_item_temp)));

        counts[i] = counts_item;
    }

    int result = findPeakIndex(counts);

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
