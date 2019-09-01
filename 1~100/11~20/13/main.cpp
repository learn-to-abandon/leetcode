#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
          int len = s.size();
          //����"IV" ��Ӧ4����3����Ϊ������"I"ʱ�ȼ�һ�����һλ"V"�жϳ�"IV"��Ҫ�ټ�3
          unordered_map <string, int> m = {{"I",1}, {"IV", 3}, {"V", 5}, {"IX", 8}, {"X", 10}, {"XL", 30}, {"L", 50}, {"XC", 80}, {"C", 100}, {"CD", 300}, {"D", 500}, {"CM", 800}, {"M", 1000}};
          int sum = m[s.substr(0,1)];
          for (int i = 1; i < len; ++i) {
                 string two = s.substr(i-1, 2);
                 string one = s.substr(i, 1);
                 if (m[two] != 0)
                     sum += m[two];
                 else
                     sum += m[one];
          }
          return sum;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("MCMXCIV") << endl;
    return 0;
}
