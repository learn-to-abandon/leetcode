#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int rx(0);
        int nx=x;
        if (x<0) return 0;
        while (x>9){
            rx=rx*10+x%10;
            x=x/10;
        }
        if (rx > INT_MAX/10 || (rx==INT_MAX/10&&x>7)) return 0;
        rx=rx*10+x;
        if (rx==nx) return 1;
        else return 0;
    }
};

int main()
{
    Solution solution;
    cout << solution.isPalindrome(2147483647) << endl;
    return 0;
}
