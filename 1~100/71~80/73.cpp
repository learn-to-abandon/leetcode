class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //首先寻找一个矩阵汇总不存在的元素作为标记值
        int flag = INT_MIN;
        while( flag++){
            int t = 0;
            for( int i = 0; i < matrix.size() && !t; i++)
                for( int j = 0; j < matrix[0].size(); j++)
                    if( matrix[i][j] == flag){
                        t = 1;
                        break;
                    }

            if( !t)
                break;
        }

        //将存在 0 的一行/列做标记
        for( int i = 0; i < matrix.size(); i++)
            for( int j = 0; j < matrix[0].size(); j++)
                if( !matrix[i][j]){
                    //那一行
                    for( int ii = 0; ii < matrix[0].size(); ii++)
                        if( matrix[i][ii])
                            matrix[i][ii] = flag;

                    //那一列
                    for( int jj = 0; jj < matrix.size(); jj++)
                        if( matrix[jj][j])
                            matrix[jj][j] = flag;
                }

        //将标记转换为 0
        for( int i = 0; i < matrix.size(); i++)
            for( int j = 0; j < matrix[0].size(); j++)
                if( matrix[i][j] == flag)
                    matrix[i][j] = 0;
    }
};
