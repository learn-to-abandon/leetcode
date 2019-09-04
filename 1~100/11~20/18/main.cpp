#include <iostream>

using namespace std;

//采用与“三数之和"类似的双指针法，只是现在多了一个数，所以多了一层循环
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size()<4)
            return {};
        //从小到大排序
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        //使用set存放结果，则无需担忧重复情况
        //上次三数之和是通过对相等值的剪枝来剪掉重复
        set<vector<int>> a;

        //固定第一个数
        for(int i=0;i<nums.size()-3;i++) {

              //去掉某个正值（四个数中最小）已经大于正和的情况
              if (nums[i]>target&&target>0) break;
              //固定第二个数
              for(int j=i+1;j<nums.size()-2;j++) {
                int l=j+1;
                int r=nums.size()-1;
                //两指针左右夹逼
                while(l<r) {
                    if(nums[i]+nums[j]+nums[l]+nums[r]<target)
                        l++;
                    else if(nums[i]+nums[j]+nums[l]+nums[r]>target)
                        r--;
                    else {
                        vector<int> temp{nums[i],nums[j],nums[l],nums[r]};
                        a.insert(temp);
                        l++;
                        r--;
                    }
                }
            }
        }
        for(auto c:a)
              res.push_back(c);

        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
