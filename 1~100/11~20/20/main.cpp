#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
             stack <char> t;
             unordered_map <char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
             int len = s.size();
             for (int i = 0; i< len; ++i) {
                    if (s[i] == '(' || s[i] == '[' || s[i] == '{' )
                        t.push(s[i]);
                    else {
                        if (!t.empty() && m[s[i]] == t.top())
                            t.pop();
                        else return false;
                    }
             }
             return t.empty();
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
