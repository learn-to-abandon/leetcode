class Solution {
public:
    int strStr(string haystack, string needle) {
          if (needle == "") return 0;
          int a = haystack.size();
          int b = needle.size();
          for (int i = 0; i < a - b + 1; ++i)
                 if (haystack.substr(i, b) == needle)
                     return i;
          return -1;
    }
};
