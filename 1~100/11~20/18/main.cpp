#include <iostream>

using namespace std;

//�����롰����֮��"���Ƶ�˫ָ�뷨��ֻ�����ڶ���һ���������Զ���һ��ѭ��
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size()<4)
            return {};
        //��С��������
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        //ʹ��set��Ž���������赣���ظ����
        //�ϴ�����֮����ͨ�������ֵ�ļ�֦�������ظ�
        set<vector<int>> a;

        //�̶���һ����
        for(int i=0;i<nums.size()-3;i++) {

              //ȥ��ĳ����ֵ���ĸ�������С���Ѿ��������͵����
              if (nums[i]>target&&target>0) break;
              //�̶��ڶ�����
              for(int j=i+1;j<nums.size()-2;j++) {
                int l=j+1;
                int r=nums.size()-1;
                //��ָ�����Ҽб�
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
