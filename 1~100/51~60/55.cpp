/*���ĳһ�������ĸ��ӿ�����Ծ�ľ�����3����ô��ʾ����3�����Ӷ�������Ϊ�����㡣
���Զ�ÿһ������Ϊ�����ĸ��Ӷ�������һ�Σ�����������Զ�ľ��벻�ϸ��¡�
�������һֱ������󣬾ͳɹ���
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int k = 0;
        for (int i = 0; i < len; i++) {
		       if (i > k) return false;
		       k = max(k, i + nums[i]);
	    }
	return true;

    }
};
