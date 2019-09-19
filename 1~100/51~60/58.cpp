class Solution {
public:
    int lengthOfLastWord(string s) {
         int len = s.size();
         if (len == 0) return 0;
         int ans = 0;
         int i = 0;

         while (i < len) {
                   if (s[i]!=' ') {
                       if ((i==0) || (i > 0 && s[i-1]!=' '))
                           ++ans;
                       if (i > 0 && s[i-1]==' ')
                           ans=1;
                   }
                   else {
                       if (i+1==len) break;
                   }
             ++i;
         }

        return ans;
    }
};
