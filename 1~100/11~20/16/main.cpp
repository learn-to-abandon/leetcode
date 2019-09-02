#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int cur = 0;
        //记录cur与target的差
        int ans = INT_MAX;

        //从小到大排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
                //两个相等的数会得到相同的数组，所以去掉
               if (i > 0 && nums[i] == nums[i - 1]) continue;

               //左指针与右指针
               int l = i + 1, r = len - 1;
               while (l < r) {
                         if (nums[l] + nums[r] + nums[i] - target< 0) {
                             if ( - nums[l] - nums[r] - nums[i] + target < ans) {
                                  cur = nums[l] + nums[r] + nums[i];
                                  ans = - nums[l] - nums[r] - nums[i] + target;
                             }
                             ++l;
                         }
                         else if (nums[l] + nums[r] + nums[i] - target> 0) {
                                if ( nums[l] + nums[r] + nums[i] - target < ans) {
                                  cur = nums[l] + nums[r] + nums[i];
                                  ans = nums[l] + nums[r] + nums[i] - target;
                             }
                                --r;
                         }
                         else
                                  return target;
                }
        }
        return cur;
    }
};

int main()
{
    return 0;
}
