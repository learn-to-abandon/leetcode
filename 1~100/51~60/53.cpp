//O(n)
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN;
        int pre = 0;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            //��¼��ǰ�ġ���Ч���ͣ�����һ������ֵС���㣬�򲻽�������������
            int cur = max(pre, 0) + nums[i];
            //��¼����
            res = max(res, cur);
            pre = cur;
        }
        return res;
    }
};
