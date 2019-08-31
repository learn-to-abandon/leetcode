#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> s;
        int n = nums.size();
        map<int, int> :: iterator it;
        for (int i = 0; i < n; ++i) {
                it = s.find(target - nums[i]);
               if (it != s.end()) {
                   vector <int> res;
                   res.push_back(s[target - nums[i]]);
                   res.push_back(i) ;
                   //cout << res[0] << "+" << res[1];
                   return res;
               }
               s.insert(pair <int, int> (nums[i], i));
        }
        return nums;
    }
};

int main()
{
    Solution solution;
    vector <int> nums;
    nums.push_back(2) ;
    nums.push_back(7) ;
    nums.push_back(11) ;
    nums.push_back(15) ;
    int target = 18;
    int s1 = solution.twoSum(nums, target)[0];
    int s2 = solution.twoSum(nums, target)[1];
    cout << s1 << " " << s2;
    return 0;
}
