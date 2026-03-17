#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findLongestArithmeticProgression' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER k
 */

int findLongestArithmeticProgression(vector<int> arr, int k) {
      // vector<int>visited(arr.size(), 0);
       unordered_map<int, int>map;
       for(int i = 0; i < arr.size(); i ++){
          map[arr[i]] ++;
       }
       sort(arr.begin(), arr.end());
       int len = 0;
       int i = 0;
       while(i < arr.size()){
         if(map.find(arr[i]) != map.end()){
            int c = 0;
            int temp = arr[i];
            while(map.find(temp) != map.end()){
                c ++;
                map.erase(temp);
                temp += k;
            }
            len = max(len, c);
         }
         i ++;
       }
       return len;
}

int main()
{
    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = findLongestArithmeticProgression(arr, k);

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
