class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0) return 0;
        stack<int> s;
        int res = 0;
        for (int i = 0; i < len; i++){
               while (!s.empty() && height[s.top()] < height[i]) {
                          int tmp = s.top();
                          s.pop();
                          if (s.empty()) break;
                          res += (min(height[i],height[s.top()]) - height[tmp]) * (i - s.top() - 1);
               }
               s.push(i);
        }
        return res;
    }
};
