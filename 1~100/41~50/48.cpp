class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int loop = 0; loop < n / 2; loop++)                    //���ѭ�������� n/2 ��
        for (int i = loop, j = loop; i < n - 1 - loop; i++) {   //�в�ѭ�������� n-1-loop���滻ѭ��
            int pre = matrix[i][j];
            for (int time = 1; time <= 4; time++) {             //�ڲ�ѭ�������� 4 ���滻����
                int tmpi = i; i = j; j = n - 1 - tmpi;
                swap(pre, matrix[i][j]);
            }
        }
}
};
