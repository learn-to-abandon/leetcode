class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 2) return len;
        int now = 1;
	    for (int i = 2; i < len;i++) {
		     if (nums[i] != nums[now - 1]){
			     ++now;
			     nums[now] = nums[i];
		     }
	    }
	    return now+1;
    }
};
