class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        long a = x/2;
        while (a*a >= x)
               a/=2;
        while (a*a <= x)
               ++a;
        return a-1;
    }
};
