class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int len = nums.size();
        for (int j = 0; j < len; ++j) {
               if (val != nums[j]) {
                   nums[i] = nums[j];
                   ++i;
               }
        }
        return i;
    }
};
