#include <iostream>
#include <string>
using namespace std;

//根据该博客判别表所写
//https://blog.csdn.net/BeforeEasy/article/details/79735776
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (p.size()==1) {
            if (s.empty()) return 0;
            if (p[0]==s[0] || p[0]=='.')
                return isMatch(s.substr(1), p.substr(1));
            else return 0;
        }
        else {
            if (p[1]!='*') {
                if (!s.empty() && (p[0]==s[0] || p[0]=='.'))
                    return isMatch(s.substr(1), p.substr(1));
                else return 0;
            }
            else {
                while (!s.empty()&&(p[0]==s[0] || p[0]=='.')) {
                    if (isMatch(s, p.substr(2))) return 1;
                    else s = s.substr(1);
                }
                return isMatch(s, p.substr(2));
            }
        }
    }
};

int main()
{
    Solution solution;
    cout << solution.isMatch("mississippi","mis*is*p*");
    return 0;
}
