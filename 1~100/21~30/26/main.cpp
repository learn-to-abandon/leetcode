class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int len = nums.size();
        if (!len) return 0;
        for (int j = 1; j < len; ++j) {
             if (nums[i] != nums[j]) {
                 ++i;
                 nums[i] = nums[j];
             }
        }
        return i+1;
    }
};
