#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
          int left_board = 0, right_board = height.size()-1;
          int vol = 0;
          while (left_board < right_board) {
                     //�Ƚϰ�����һ������������֮������С
                     int h = height[left_board] < height[right_board] ? height[left_board++] : height[right_board--];
                     int cur = h * (right_board - left_board +1);
                     if (cur > vol) vol = cur;
          }
          return vol;
    }
};

int main()
{

    return 0;
}
