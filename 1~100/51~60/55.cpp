/*如果某一个起跳的格子可以跳跃的距离是3，那么表示后面3个格子都可以作为起跳点。
可以对每一个能作为起跳的格子都尝试跳一次，把能跳到最远的距离不断更新。
如果可以一直跳到最后，就成功了
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
