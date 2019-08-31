#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/* O(log(m+n))Ҫ�����ʹ�ö��ַ�����ʼ�ȴ�����һ��Ϊ�յ�������Ƚϼ򵥣�������е��벻�����
    ������������ṩ��һ�ֽⷨ������Ҳ�Ƚϼ���׶�

    ����������������λ��������һ�㻯Ϊ����������������ĵ�k��������k = (m+n)/2ʱΪԭ����Ľ⡣
    ��ô���k�������ֱ������һ���͵ڶ�������ĵ� k / 2���� a �� b��Ȼ��Ƚ� a �� b����a < b ��˵���� k ����λ�� a����ĵ� k / 2�������Σ�����b����� �� k / 2 ����ǰ��Σ������ģ��С��һ�룬Ȼ��ݹ鴦����С�
    ʱ�临�Ӷ��� O(log(m+n))

 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //��һ��Ϊ��
        if (n1 == 0) {
            if (n2 %2 == 1)
                return nums2[n2/2];
            else
                return (double) (nums2[n2/2-1]+nums2[n2/2])/2;
        }
        if (n2 == 0) {
            if (n1 % 2 == 1)
                return (double) nums1[n1/2];
            else
                return (double) (nums1[n1/2-1]+nums1[n1/2])/2;
        }

        int total = n1 + n2;
        //����Ϊ�������ҵ� total / 2 + 1 ����
        if ((total & 1) == 1)
            return find_kth(nums1, 0, nums2, 0, total / 2 + 1);
        //����Ϊż�����ҵ� total / 2 �����͵�total / 2 + 1������ƽ��ֵ
        return (find_kth(nums1, 0, nums2, 0, total / 2) + find_kth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    }

    //Ѱ��a �� b �����У���k������
    double find_kth(vector<int>& a, int a_begin, vector<int>& b, int b_begin, int k) {
        //��a �� b �������鳤�ȣ����k����Ϊ����һ�������k����
        if (a_begin >= a.size())
            return b[b_begin + k - 1];
        if (b_begin >= b.size())
            return a[a_begin + k - 1];
        //kΪ1ʱ����������С���Ǹ�Ϊ��һ����
        if (k == 1)
            return a[a_begin] < b[b_begin] ? a[a_begin] : b[b_begin];

        int mid_a = INT_MAX;
        int mid_b = INT_MAX;
        //mid_a / mid_b �ֱ��ʾ a���顢b�����е� k / 2 ����
        if (a_begin + k / 2 - 1 < a.size())
            mid_a = a[a_begin + k / 2 - 1];
        if (b_begin + k / 2 - 1 < b.size())
            mid_b = b[b_begin + k / 2 - 1];
        //���a����ĵ� k / 2 ����С��b����ĵ� k / 2 ��������ʾ�ܵĵ� k ����λ�� a�ĵ�k / 2�����ĺ��Σ�������b�ĵ� k / 2������ǰ���
        //���ڷ�Χ��С�� k / 2 ��������ʱ�ܵĵ� k ����ʵ���ϵ����µķ�Χ�ڵĵ� k - k / 2���������εݹ�
        if (mid_a < mid_b)
            return find_kth(a, a_begin + k / 2, b, b_begin, k - k / 2);
        //�����෴
        return find_kth(a, a_begin, b, b_begin + k / 2, k - k / 2);
    }

};

int main()
{
    vector <int> nums1,nums2;
    nums1.push_back(1);
    nums1.push_back(4);
    nums2.push_back(2);
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    //cout << nums1[1];
    return 0;
}
