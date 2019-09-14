class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int ans = 1;
        for (int i = 0; i < len; ++i) {
             if (nums[i] == ans) ++ans;
             else if (nums[i] > ans) break;
        }
        return ans;
    }
};
