class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //����Ѱ��һ��������ܲ����ڵ�Ԫ����Ϊ���ֵ
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

        //������ 0 ��һ��/�������
        for( int i = 0; i < matrix.size(); i++)
            for( int j = 0; j < matrix[0].size(); j++)
                if( !matrix[i][j]){
                    //��һ��
                    for( int ii = 0; ii < matrix[0].size(); ii++)
                        if( matrix[i][ii])
                            matrix[i][ii] = flag;

                    //��һ��
                    for( int jj = 0; jj < matrix.size(); jj++)
                        if( matrix[jj][j])
                            matrix[jj][j] = flag;
                }

        //�����ת��Ϊ 0
        for( int i = 0; i < matrix.size(); i++)
            for( int j = 0; j < matrix[0].size(); j++)
                if( matrix[i][j] == flag)
                    matrix[i][j] = 0;
    }
};
