#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/* O(log(m+n))要求该题使用二分法，开始先处理有一个为空的情况，比较简单，后面就有点想不清楚了
    后面是题解中提供的一种解法，解释也比较简洁易懂

    两个有序数组求中位数，问题一般化为，求两个有序数组的第k个数，当k = (m+n)/2时为原问题的解。
    怎么求第k个数？分别求出第一个和第二个数组的第 k / 2个数 a 和 b，然后比较 a 和 b，当a < b ，说明第 k 个数位于 a数组的第 k / 2个数后半段，或者b数组的 第 k / 2 个数前半段，问题规模缩小了一半，然后递归处理就行。
    时间复杂度是 O(log(m+n))

 */


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        //有一个为空
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
        //总数为奇数，找第 total / 2 + 1 个数
        if ((total & 1) == 1)
            return find_kth(nums1, 0, nums2, 0, total / 2 + 1);
        //总数为偶数，找第 total / 2 个数和第total / 2 + 1个数的平均值
        return (find_kth(nums1, 0, nums2, 0, total / 2) + find_kth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    }

    //寻找a 和 b 数组中，第k个数字
    double find_kth(vector<int>& a, int a_begin, vector<int>& b, int b_begin, int k) {
        //当a 或 b 超过数组长度，则第k个数为另外一个数组第k个数
        if (a_begin >= a.size())
            return b[b_begin + k - 1];
        if (b_begin >= b.size())
            return a[a_begin + k - 1];
        //k为1时，两数组最小的那个为第一个数
        if (k == 1)
            return a[a_begin] < b[b_begin] ? a[a_begin] : b[b_begin];

        int mid_a = INT_MAX;
        int mid_b = INT_MAX;
        //mid_a / mid_b 分别表示 a数组、b数组中第 k / 2 个数
        if (a_begin + k / 2 - 1 < a.size())
            mid_a = a[a_begin + k / 2 - 1];
        if (b_begin + k / 2 - 1 < b.size())
            mid_b = b[b_begin + k / 2 - 1];
        //如果a数组的第 k / 2 个数小于b数组的第 k / 2 个数，表示总的第 k 个数位于 a的第k / 2个数的后半段，或者是b的第 k / 2个数的前半段
        //由于范围缩小了 k / 2 个数，此时总的第 k 个数实际上等于新的范围内的第 k - k / 2个数，依次递归
        if (mid_a < mid_b)
            return find_kth(a, a_begin + k / 2, b, b_begin, k - k / 2);
        //否则相反
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
