#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        int len = nums.size();
        vector<vector<int>> ans;
        //从小到大排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
                //两个相等的数会得到相同的数组，所以去掉
               if (i > 0 && nums[i] == nums[i - 1]) continue;
               //只遍历非正数，因为每个数组中必有非正数
               if ((target = nums[i]) > 0) break;
               //左指针与右指针
               int l = i + 1, r = len - 1;
               while (l < r) {
                         if (nums[l] + nums[r] + target < 0) ++l;
                         else if (nums[l] + nums[r] + target > 0) --r;
                         else {
                                  ans.push_back({target, nums[l], nums[r]});
                                  ++l, --r;
                                   //两个相等的数会得到相同的数组，所以去掉
                                  while (l < r && nums[l] == nums[l - 1]) ++l;
                                  while (l < r && nums[r] == nums[r + 1]) --r;
                         }
                }
        }
        return ans;
    }
};

int main()
{
    return 0;
}
