#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'searchRotatedTimestamps' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY nums
 *  2. INTEGER target
 */

int searchRotatedTimestamps(vector<int> nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(nums[mid] == target)
          return mid;
        if(nums[low] <= nums[mid]){
            //left sorted
            if(nums[low] <= target && target <= nums[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    string nums_count_temp;
    getline(cin, nums_count_temp);

    int nums_count = stoi(ltrim(rtrim(nums_count_temp)));

    vector<int> nums(nums_count);

    for (int i = 0; i < nums_count; i++) {
        string nums_item_temp;
        getline(cin, nums_item_temp);

        int nums_item = stoi(ltrim(rtrim(nums_item_temp)));

        nums[i] = nums_item;
    }

    string target_temp;
    getline(cin, target_temp);

    int target = stoi(ltrim(rtrim(target_temp)));

    int result = searchRotatedTimestamps(nums, target);

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
