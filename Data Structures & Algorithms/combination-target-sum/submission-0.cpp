class Solution {
public:
    vector<vector<int>> result;
    void solve(int i, vector<int>& nums, int target,
               vector<int>& temp, int sum) {
        if (sum == target) {
            result.push_back(temp);
            return;
        }
        if (sum > target || i == nums.size()) {
            return;
        }
        temp.push_back(nums[i]);
        solve(i, nums, target, temp, sum + nums[i]);
        temp.pop_back();
        solve(i + 1, nums, target, temp, sum);}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve(0, nums, target, temp, 0);
        return result;
    }
};