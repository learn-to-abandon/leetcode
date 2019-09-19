class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int loop = 0; loop < n / 2; loop++)                    //外层循环：处理 n/2 层
        for (int i = loop, j = loop; i < n - 1 - loop; i++) {   //中层循环：处理 n-1-loop次替换循环
            int pre = matrix[i][j];
            for (int time = 1; time <= 4; time++) {             //内层循环：处理 4 次替换过程
                int tmpi = i; i = j; j = n - 1 - tmpi;
                swap(pre, matrix[i][j]);
            }
        }
}
};
