/*对于给定一个集合里，所有元素的集合它们应该满足这样一个公式: 假设所有的组合数之和为sum，则有sum = C(n, 0) + C(n, 1) + ...+ C(n, n); 分别对应取集合中的一个元素，两个元素...n个元素。而通过数学公式二项式定义，这个和是等于2 ** n（2的n次方）。就是说，我们所有取的组合数为一个指数函数。
假设输入是1、2、3。
首先全部的子集为【000】【001】【010】【100】【011】【101】【110】【111】
1表示这一位的数字存在，例如 【010】 表示只含有 2
由此发现子集所代表的二进制数全部小于    1 << 数组.length
第一层循环
for (int i = 0; i < (1 << size); i++)
然后根据【i】 的二进制数中 【1】 的位置取得子集
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int S = nums.size();
        int N = 1 << S;
        vector<vector<int> > res;
        for (int i = 0; i < N; ++i) {
            vector<int> v;
            for (int j = 0; j < S; ++j)
                if (i & (1 << j))
                    v.push_back(nums[j]);
            res.push_back(v);
        }
        return res;
    }
};
