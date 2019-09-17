class Solution {
public:
    string multiply(string num1, string num2) {
               int n1 = num1.size();
               int n2 = num2.size();
               string s(n1 + n2, '0');

               for (int i = n1-1; i >= 0; --i) {
                      for (int j = n2-1; j>=0; --j) {
                             int m = (s[i+j+1]-'0')+(num1[i]-'0')*(num2[j]-'0');
                             s[i+j+1] =m % 10+'0';
                             s[i+j]+=m / 10;
                      }
               }

               while (s[0]=='0' && s.size()>1)
                          s = s.substr(1, s.size()-1);
               return s;
    }
};
