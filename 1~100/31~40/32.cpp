//反向遍历两次，应对 (() 类似情况
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0;
        int mark = 0;
        for (int i = 0; i < s.size(); ++i) {
            int prev_mark = mark;

            mark = max(0, mark + ((s[i] == '(') ? 1 : -1));
            if (mark == 0) {
                //形成闭合括号，计算右括号数
                if (prev_mark > 0) {
                    res = max(i - left + 1, res);
                }
                //未形成闭合括号且当前为），所以左指针前移
                else {
                    left = i + 1;
                }
            }
        }
        /*
        mark = 0;
        int right = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            int prev_mark = mark;

            mark = max(0, mark + ((s[i] == ')') ? 1 : -1));
            if (mark == 0) {
                if (prev_mark > 0) {
                    res = max(right - i + 1, res);
                } else {
                    right = i - 1;
                }
            }
        }*/
        return res;
    }
};
