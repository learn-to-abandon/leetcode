class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int len = nums.size();
         if (len == 0) return 0;
         if (target > nums[len-1]) return len;
         if (target < nums[0]) return 0;

         int left = 0;
         int right = len - 1;
         int mid = (left+right)/2;

         while (nums[left] < nums[right]) {
            if (nums[mid] < target) {
                left = mid+1;
                mid = (left+right)/2;
            }
            else if (nums[mid] > target) {
                right = mid-1;
                mid = (left+right)/2;
            }
            else return mid;
         }
         while (nums[mid] < target) ++mid;
         //cout << left << " " << right << " " << mid;

         return mid;
    }
};
