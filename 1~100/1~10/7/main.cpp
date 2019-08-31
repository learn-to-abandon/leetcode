#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int y(0);
        int sign(1);
        int t;

        if (x<0) {
            if (x==-2147483648) return 0;
            sign=-1;
            x=-x;
        }
        while (x>=10&&x!=0){
            t=y;
            y=y*10+x%10;
            x=x/10;
            if (y/10!=t) return 0;
        }
        t=y;
        if (y > INT_MAX/10 || (y == INT_MAX/10 && x%10>7)) return 0;
        y=y*10+x%10;
        if (y/10!=t) return 0;

        return y*sign;
        }
};

int main()
{
    Solution solution;
    int x =123;
    cout << solution.reverse(x);
    return 0;
}
