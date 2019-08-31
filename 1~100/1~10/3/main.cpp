#include <iostream>
#include <map>
using namespace std;

    class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;
        map<char, int> m;

        for (int j = 0, i = 0; j < n; j++) {
               if (m.find(s[j]) != m.end()) {
                    //map中已经存在该字符，将该字符起始位置更改

                    //cout << i << " " <<  j << " " << s[j] << " " << m[s[j]] << endl;
                    if ((m[s[j]] > i))
                        i = m[s[j]];

               }
               //记录当前最大值
               ans = (ans > j - i + 1) ? ans : j - i + 1;
               //字符存入map
               m[s[j]] = j+1;
               //cout << m[s[j]] << endl;
        }
        return ans;
    }
};

int main()
{
    string s = "dvdf";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
