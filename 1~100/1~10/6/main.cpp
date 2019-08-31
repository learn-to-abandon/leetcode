#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
         string q;
         int len = s.size();

         if (numRows==1) return s;

         for (int i = 0; i < len; i+=2*numRows-2)
                q+=s[i];

         if (numRows > 2) {
         for (int i = 1; i < numRows-1; ++i) {
                int j = i;
                while (j < len) {
                          q+=s[j];
                          j+=2*(numRows-i-1);
                          if (j<len) {
                              q+=s[j];
                              j+=2*i;
                          }
                }
         }
         }

         for (int i = numRows-1; i < len; i+=2*numRows-2)
                q+=s[i];
         return q;
    }
};

int main()
{
    Solution solution;
    string s = "a";
    int numRows = 1;
    cout << solution.convert(s, numRows);
    return 0;
}
