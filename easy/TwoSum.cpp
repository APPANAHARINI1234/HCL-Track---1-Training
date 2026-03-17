#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findTaskPairForSlot' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY taskDurations
 *  2. INTEGER slotLength
 */

vector<int> findTaskPairForSlot(vector<int> taskDurations, int slotLength) {
  unordered_map<int, int>map;
  for(int i = 0; i < taskDurations.size(); i ++){
    int target = slotLength - taskDurations[i];
    if(map.find(target) != map.end()){
        vector<int>ans(2, 0);
        ans[0] = map[target];
        ans[1] = i;
        return ans;
    }
    map[taskDurations[i]] = i;
  }
  vector<int>ans(2, -1);
    return ans;
}

int main()
{
    string taskDurations_count_temp;
    getline(cin, taskDurations_count_temp);

    int taskDurations_count = stoi(ltrim(rtrim(taskDurations_count_temp)));

    vector<int> taskDurations(taskDurations_count);

    for (int i = 0; i < taskDurations_count; i++) {
        string taskDurations_item_temp;
        getline(cin, taskDurations_item_temp);

        int taskDurations_item = stoi(ltrim(rtrim(taskDurations_item_temp)));

        taskDurations[i] = taskDurations_item;
    }

    string slotLength_temp;
    getline(cin, slotLength_temp);

    int slotLength = stoi(ltrim(rtrim(slotLength_temp)));

    vector<int> result = findTaskPairForSlot(taskDurations, slotLength);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

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
