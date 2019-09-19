//O(n)
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN;
        int pre = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            //记录当前的“有效”和，若上一个数组值小于零，则不将这个数加入算和
            int cur = max(pre, 0) + nums[i];
            //记录最大和
            res = max(res, cur);
            pre = cur;
        }
        return res;
    }
};
