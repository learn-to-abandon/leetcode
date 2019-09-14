class Solution {
public:
    string countAndSay(int n) {
               stack <string> s;
               s.push("1");
               while (n>1) {
                     string pre = s.top();
                     string cur;
                     int len = pre.size();
                     char c = pre[0];
                     int m = 0;
                     for (int i = 0; i < len; ++i) {
                            if (c == pre[i])
                                ++m;
                            else {
                                char q = (char) ('0'+m);
                                char w = (char) c;
                                cur += q;
                                cur += w;
                                m = 1;
                                c = pre[i];
                            }
                     }
                     cur += '0'+m;
                     cur += c;
                     s.push(cur);
                     --n;
               }
               return s.top();
    }
};
