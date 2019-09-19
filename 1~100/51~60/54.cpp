class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
              vector <int> ans;
              int row = matrix.size();
              if (row==0) return ans;
              int col = matrix[0].size();

              int loop = row/2;
              for (int i = 0; i < loop; ++i) {
                     for (int j = loop; j < row - loop)
              }
    }
};
