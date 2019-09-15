/*#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
           vector < vector <char> > board[9][9] ;
           for(int i=0;i<9;++i)
               for(int j=0;j<9;++j)
                    cin>>board[i][j];

            bool b[3][9][9] = {0};

            for (int i = 0; i < 9; ++i) {
                   for (int j = 0; j < 9; ++j) {
                          if (board[i][j] != '.') {
                               int a = (int) (board[i][j] - '1');
                               b[0][i][a] = 1;
                               b[1][j][a] = 1;

                               int dis = i / 3 * 3 + j % 3;
                               b[2][dis][a] = 1;
                          }
                   }
            }

            stack <int> x;
            stack <int> y;
            stack <int> z;
            z.push(0);

            for (int i = 0; i < 9; ++i) {
                   for (int j = 0; j < 9; ++j) {

                          if (board[i][j] == '.') {
                               bool n[9] = {0};

                               for (int q = 0; q < 9; ++q) {
                                    if (b[0][i][q] == 1)
                                        n[q] = 1;

                               }

                               for (int q = 0; q < 9; ++q) {
                                    if (b[1][j][q] == 1)
                                        n[q] = 1;

                               }

                               for (int q = 0; q < 9; ++q) {
                                    if (b[2][i/3*3+j%3][q] == 1)
                                        n[q] = 1;

                               }

                               bool s = 0;
                               for (int q = z.top(); q < 9; ++q) {
                                      if (n[q] == 0) {
                                          board[i][j] = (char) ('1' + q);
                                          s = 1;
                                          x.push(i);
                                          y.push(j);
                                          z.pop();
                                          z.push(q+1);
                                          z.push(0);
                                          //so(board,b);
                                          break;
                                      }
                               }
                                      if (s == 0){
                                      i = x.top();
                                      j = y.top();
                                      x.pop();
                                      y.pop();
                                      z.pop();
                                      board[i][j] = '.';
                                      }
                          }
                   }
            }
    }
*/

    class Solution {
public:
    bool solved = 0;
	bool row[9][10], col[9][10], box[9][10];
	void solveSudoku(vector<vector<char>>& board) {
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(box, 0, sizeof(box));
		for(int i=0;i<9;i++)
			  for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				int index = i / 3 * 3 + j / 3;
				int num = board[i][j] - '0';
				row[i][num] = col[j][num] = box[index][num] = 1;
			  }
		DFS(0, 0, board);
	}
	void DFS(int i, int j, vector<vector<char>>& board) {
		if (i == 9) { solved = 1; return; }
		if (board[i][j] != '.') {
			if (j < 8) DFS(i, j + 1, board);
			else DFS(i + 1, 0, board);
		}
		else {
			int index = i / 3 * 3 + j/3;
			for (int num = 1; num <= 9; num++) {
				if (!row[i][num] && !col[j][num] && !box[index][num]) {
					board[i][j] = num + '0';
					row[i][num] = col[j][num] = box[index][num] = 1;
					if (j < 8) DFS(i, j + 1, board);
					else DFS(i + 1, 0, board);
					if (!solved) { //»ØËÝ
						row[i][num] = col[j][num] = box[index][num] = 0;
						board[i][j] = '.';
					}
				}
			}
		}
	}

};
