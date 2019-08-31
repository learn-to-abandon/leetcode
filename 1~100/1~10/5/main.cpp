#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
               int l = s.size();
               string res;
                    if (l == 1) return s;
                    if (l == 2) {
                           if (s[0]==s[1]) return s;
                           else return s.substr(0,1);
                       }

                    for (int i = 1; i < l-1; ++i) {
                           int max_step = i < (l-i-1) ? i : (l-i-1);
                           if (2*max_step+1 <= res.size()) continue;
                           bool flag = 1;
                           for (int j = 1; j <= max_step;++j) {
                                  if (s[i-j]!=s[i+j]) {
                                      if (res.size()>=2*j-1) break;
                                      else if (flag){res = s.substr(i-j+1,2*j-1);
                                      cout << i << s[i-j] << s[i+j]<< " " << res << endl;}
                                      flag=0;
                                  }
                                  else {
                                    if (j == max_step && res.size()<2*j+1 && flag) res = s.substr(i-j,2*j+1);
                                  }
                           }

                   }


                   for (int i = 0; i < l - 1; ++i) {
                          int max_step = i < (l-i-2) ? i : (l-i-2);
                          if (2*max_step+2 <= res.size()) continue;
                          bool flag = 1;
                              for (int j = 0; j <= max_step; ++j) {
                                     if (s[i-j]!=s[i+1+j]) {
                                         if (res.size()>=2*j) break;
                                         else if (flag) res = s.substr(i-j+1,2*j);
                                         flag=0;
                                     }
                                     else
                                           if (j == max_step && res.size()<2*j+2 && flag) res = s.substr(i-j,2*j+2);

                              }

                   }

                   return res;
    }
};

int main()
{
    Solution solution;
    string s="babaddtattarrattatddetartrateedredividerb";
    cout << solution.longestPalindrome(s);
    return 0;
}
