#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
               if (strs.empty()) return "";
               if (strs.size() == 1) return strs[0];
               string s="";

               for (int i=0;i<strs[0].size();++i) {
                      for (int j=0;j<strs.size();++j)
                             if(strs[0][i]!=strs[j][i])
                                return s;
                      s+=strs[0][i];
               }
               return s;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
