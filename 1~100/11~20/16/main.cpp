#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int cur = 0;
        //��¼cur��target�Ĳ�
        int ans = INT_MAX;

        //��С��������
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
                //������ȵ�����õ���ͬ�����飬����ȥ��
               if (i > 0 && nums[i] == nums[i - 1]) continue;

               //��ָ������ָ��
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
