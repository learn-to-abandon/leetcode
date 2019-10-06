class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        stack<int> sk;
        int area = 0;
        //��heights�з���һ��0�������Ϳ��Խ�֮ǰ�ĵ������ж�pop����
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i ++) {
            while (!sk.empty() && heights[i] < heights[sk.top()]) {
                int top = sk.top();
                sk.pop();
                int w = sk.empty() ? i : i - sk.top() - 1;
                area = max(area, w * heights[top]);
            }
            sk.push(i);
        }
        return area;
    }
};
