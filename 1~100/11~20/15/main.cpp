#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        int len = nums.size();
        vector<vector<int>> ans;
        //��С��������
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len; i++) {
                //������ȵ�����õ���ͬ�����飬����ȥ��
               if (i > 0 && nums[i] == nums[i - 1]) continue;
               //ֻ��������������Ϊÿ�������б��з�����
               if ((target = nums[i]) > 0) break;
               //��ָ������ָ��
               int l = i + 1, r = len - 1;
               while (l < r) {
                         if (nums[l] + nums[r] + target < 0) ++l;
                         else if (nums[l] + nums[r] + target > 0) --r;
                         else {
                                  ans.push_back({target, nums[l], nums[r]});
                                  ++l, --r;
                                   //������ȵ�����õ���ͬ�����飬����ȥ��
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
