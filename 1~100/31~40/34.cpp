/*class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        vector <int> ans;
        if (len == 0) return ans;
        int le = 0;
        int ri = len - 1;
        int mid = (le + ri)/2;
        while (le <= ri) {
            bool l = 0;
            bool r = 0;
            if (nums[le] < target) {
                le = mid + 1;
                mid = (le + ri)/2;
            }
            else l = 1;
            if (nums[ri] > target) {
                ri = mid-1;
                mid = (le + ri)/2;
            }
            else r = 1;
            if (l && r) break;
        }
        //cout << nums[le] << le << endl;
        //cout << nums[ri] << ri;
        while (nums[le] >= target)
                   --le;
        while (nums[ri] <= target)
                   ++ri;
        if (nums[le+1]!=target) {
            le=-2;
            ri=0;
        }
        ans.push_back(le+1);
        ans.push_back(ri-1);
        return ans;
    }
};*/
//上面的二分法没通过提交，但感觉差不多了，应该是一些特殊情况没考虑
class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
vector<int> ans;
    if (nums.empty()) {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    vector<int>::iterator left = lower_bound(nums.begin(), nums.end(), target);
    vector<int>::iterator right = upper_bound(nums.begin(), nums.end(), target);

    if (left == nums.end() || *left != target) {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else {
        ans.push_back(left - nums.begin());
        ans.push_back(right - nums.begin() - 1);
    }

    return ans;
}
};


