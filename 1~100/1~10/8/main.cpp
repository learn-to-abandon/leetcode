#include <iostream>
#include <limits>
#include<sstream>
using namespace std;

//��ʶ��istringstream������
//https://blog.csdn.net/jacky_chenjp/article/details/70233212
class Solution {
public:
    int myAtoi(string str) {
        int d;
        istringstream is(str);
        is >> d;
        return d;
    }
};

int main()
{
    Solution solution;
    cout << solution.myAtoi("     345   wer");
}
