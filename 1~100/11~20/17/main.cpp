#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
               vector<string> ans;
               if (digits.empty()) return ans;
               unordered_map <int, string> m = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

               while (digits.size() !=0 ) {
                   int n = m[digits[0]-'0'].size();
                   if (ans.size() == 0) {
                   for (int i = 0; i < n; ++i)
                          ans.push_back(m[digits[0]-'0'].substr(i, 1));
               }

               else {
                   int l = ans.size();
                   for (int i = 0; i <l; ++i)
                          for (int j = 0; j < n; ++j) {
                                 ans.push_back(ans[i]+m[digits[0]-'0'].substr(j, 1));
                                 //cout << ans[i]+m[digits[0]-'0'].substr(j, 1);
                          }
                    ans.erase(ans.begin(), ans.begin()+l);
               }
               //cout << "a"<<digits << endl;
               digits = digits.substr(1,digits.size()-1);
               //cout << "b"<<digits << endl;
               }

               return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
