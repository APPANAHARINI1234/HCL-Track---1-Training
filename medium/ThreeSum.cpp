class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n - 2; ) {
            int j = i + 1;
            int k = n - 1;
            int target = -nums[i];

            while(j < k) {
                int sum = nums[j] + nums[k];

                if(sum == target) {
                    res.push_back({nums[i], nums[j], nums[k]});

                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                }
                else if(sum > target) {
                    k--;
                }
                else {
                    j++;
                }
            }

            while(i < n - 2 && nums[i] == nums[i + 1]) i++;
            i++;
        }

        return res;
    }
};