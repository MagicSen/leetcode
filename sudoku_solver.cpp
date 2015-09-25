#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;
class Solution {
	public:
		bool isVaild(char ch, int i, int j, map<int, set<char>> rows, map<int, set<char>> cols, map<int, set<char>> cell, vector<vector<int>> cell_index, vector<int> c, int r, vector<vector<int> > unknow_index){
			string dict = "123456789";
			if(rows[i].find(ch) != rows[i].end() || cols[j].find(ch) != cols[j].end() || cell[cell_index[i][j]].find(ch) != cell[cell_index[i][j]].end()){
				return false;
			}else{
				for(int k = 0; k < r; ++k){
					if(dict[c[k]] == ch && (unknow_index[k][0] == i || unknow_index[k][1] == j || cell_index[i][j] == cell_index[unknow_index[k][0]][unknow_index[k][1]] ))
						return false;
				}
				return true;
			}
		}

		void solveSudoku(vector<vector<char>>& board) {
			map<int, set<char> > rows;	
			map<int, set<char> > cols;	
			map<int, set<char> > cell;
			vector<vector<int> > unknow_index;
			int n = board.size();
			vector<vector<int>> cell_index(n, vector<int>(n, 0));
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++ j){
					if(i < 3 && j < 3){
						cell_index[i][j] = 0;
					}else if(i < 3 && j >= 3 && j < 6){
						cell_index[i][j] = 1;
					}else if(i < 3 && j >= 6 && j < 9){
						cell_index[i][j] = 2;
					}else if(i < 6 && j < 3){
						cell_index[i][j] = 3;
					}else if(i < 6 && j >=3 && j < 6){
						cell_index[i][j] = 4;
					}else if(i < 6 && j >= 6 && j < 9){
						cell_index[i][j] = 5;
					}else if(i < 9 && j < 3){
						cell_index[i][j] = 6;
					}else if(i < 9 && j >=3 && j < 6){
						cell_index[i][j] = 7;
					}else if(i < 9 && j >= 6 && j < 9){
						cell_index[i][j] = 8;
					}
				}
			}
			for(int i = 0; i < n; ++i){
				for(int j = 0; j < n; ++j){
					if(board[i][j] != '.'){
						rows[i].insert(board[i][j]);
						cols[j].insert(board[i][j]);
						cell[cell_index[i][j]].insert(board[i][j]);
					}else{
						vector<int> index;
						index.push_back(i);
						index.push_back(j);
						unknow_index.push_back(index);
					}
				}
			}
			//	printMap(rows);
			//	printMap(cols);
			//	printMap(cell);
			vector<int> c(unknow_index.size(), 0);
			int r = 0;
			string dict = "123456789";
			while(1){
				if(r == unknow_index.size()){
					for(int l = 0; l < unknow_index.size(); ++l){
						board[unknow_index[l][0]][unknow_index[l][1]] = dict[c[l]];
					}
					break;
				}else if(c[r] == 9){
					c[r--] = 0;
					if(r == -1){
						break;
					}
					// Delete the dict;
					c[r]++;
				}else if(!isVaild(dict[c[r]], unknow_index[r][0], unknow_index[r][1], rows, cols, cell, cell_index, c, r, unknow_index)){
					c[r]++;
				}else{
					r++;
				}
			}
		}
		void printVector(vector<vector<char>>& matrix){
			for(int i = 0; i <matrix.size(); ++ i){
				for(int j = 0; j < matrix[i].size(); ++j){
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
		void printMap(map<int, set<char>> table_1){
			cout << "###########################" << endl;
			for(auto i = table_1.begin(); i != table_1.end(); ++i){
				set<char> k = i->second;
				cout << i->first << ":" << endl;
				for(auto j : k){
					cout << j << " ";
				}
				cout << endl;
			}
		}
};
int main(){
	return 0;
}
