#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int n = num % 10;
        num = num / 10;
        int ten = num % 10;
        num = num / 10;
        int hun = num % 10;
        num = num  / 10;
        int thou = num;
        string s;

        if (thou != 0) {
            for (int i = 0; i < thou; ++i)
                   s+="M";
        }

        if (hun != 0) {
            if (hun < 4) {
                for (int i = 0; i < hun; ++i)
                   s+="C";
            }
            else if (hun == 4)
                s+="CD";
            else if (hun == 9)
                s+="CM";
            else {
                s+="D";
                for (int i = 0; i < hun-5; ++i)
                   s+="C";
            }
        }

        if (ten != 0) {
            if (ten < 4) {
                for (int i = 0; i < ten; ++i)
                   s+="X";
            }
            else if (ten == 4)
                s+="XL";
            else if (ten == 9)
                s+="XC";
            else {
                s+="L";
                for (int i = 0; i < ten-5; ++i)
                   s+="X";
            }
        }

        if (n != 0) {
            if (n < 4) {
                for (int i = 0; i < n; ++i)
                   s+="I";
            }
            else if (n == 4)
                s+="IV";
            else if (n == 9)
                s+="IX";
            else {
                s+="V";
                for (int i = 0; i < n-5; ++i)
                   s+="I";
            }
        }

        return s;
    }
};

int main()
{
    Solution solution;
    cout << solution.intToRoman(1994) << endl;
    return 0;
}
