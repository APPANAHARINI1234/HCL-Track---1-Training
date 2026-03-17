#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'debounceTimestamps' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY timestamps
 *  2. INTEGER K
 */

int debounceTimestamps(vector<int> timestamps, int K) {
     int validcount = 1;
     int i = 0;
     int j = 1;
     if(timestamps.size() == 0)
       return 0;
     while(j < timestamps.size()){
        if(timestamps[j] - timestamps[i] >= K){
            validcount ++;
            i = j;
        }
        j ++;
     }
     return validcount;;
}

int main()
{
    string timestamps_count_temp;
    getline(cin, timestamps_count_temp);

    int timestamps_count = stoi(ltrim(rtrim(timestamps_count_temp)));

    vector<int> timestamps(timestamps_count);

    for (int i = 0; i < timestamps_count; i++) {
        string timestamps_item_temp;
        getline(cin, timestamps_item_temp);

        int timestamps_item = stoi(ltrim(rtrim(timestamps_item_temp)));

        timestamps[i] = timestamps_item;
    }

    string K_temp;
    getline(cin, K_temp);

    int K = stoi(ltrim(rtrim(K_temp)));

    int result = debounceTimestamps(timestamps, K);

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
