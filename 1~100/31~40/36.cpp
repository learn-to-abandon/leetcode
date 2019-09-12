class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map <char, int> m = {{'1',0}, {'2',1}, {'3',2}, {'4',3}, {'5',4}, {'6',5}, {'7',6}, {'8',7}, {'9',8}};
        for (int i = 0; i < 9; ++i) {
               bool b[9] = {0};
               for (int j = 0; j < 9; ++j) {
                      if (board[i][j] != '.') {
                          if (b[m[board[i][j]]] == 1)
                              return 0;
                          else b[m[board[i][j]]] = 1;
                      }
                      //cout << board[i][j] << " ";
               }
               //cout << "\n";
        }

        for (int i = 0; i < 9; ++i) {
               bool b[9] = {0};
               for (int j = 0; j < 9; ++j) {
                      if (board[j][i] != '.') {
                          if (b[m[board[j][i]]] == 1)
                              return 0;
                          else b[m[board[j][i]]] = 1;
                      }
                      //cout << board[i][j] << " ";
               }
               //cout << "\n";
        }

        int x[8] = {-1,0,1,1,1,0,-1,-1};
        int y[8] = {-1,-1,-1,0,1,1,1,0};

        for (int i = 1; i < 9; i+=3) {
               for (int j = 1; j < 9; j+=3) {
                      bool b[9] = {0};
                      if (board[i][j] != '.') b[m[board[i][j]]] = 1;
                      cout << board[i][j] << " ";
                      for (int k = 0; k < 8; ++k) {
                             if (board[i+x[k]][j+y[k]] != '.') {
                                  if (b[m[board[i+x[k]][j+y[k]]]] == 1)
                                      return 0;
                                  else b[m[board[i+x[k]][j+y[k]]]] = 1;
                             }
                             //cout << board[i+x[k]][j+y[k]] << " ";
                      }
                      //cout << "\n";
               }
        }

        return 1;
    }
};
