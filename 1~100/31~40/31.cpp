class Solution {
public:
    void nextPermutation(vector<int>& nums) {
                int flag = 0;
    int i = nums.size() - 1;
    for(; i > 0; i--)
    {
        if(nums[i - 1] < nums[i])
        {
            flag = i - 1;
            break;
        }
    }

    if(i == 0)//��������һ����������
        sort(nums.begin(),nums.end());//�����ų���С����
    else
    {
        sort(nums.begin() + i,nums.end());
        int j = i;
        for(; j < nums.size(); j++)
            if(nums[j] > nums[flag]) break;//�ҵ��պô���a[flag]����
        //����������
        int t = nums[flag];
        nums[flag] = nums[j];
        nums[j] = t;
    }
    }
};
