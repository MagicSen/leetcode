#include "iostream"
#include "string"
#include "vector"
#include "cmath"

using namespace std;

class Solution {
public:
	bool isValid(vector<int> col, int row, int col_number){
		for(int i = 0; i < row; ++i)
			if(col[i] == col_number || abs(col[i] - col_number) == abs(i - row))
				return false;
		return true;
	}

    	vector<vector<string> > solveNQueens(int n) {
		vector<int> col(n, 0);
		int row = 0;
		vector<vector<string>> result;
		while(1){
			if(row == n){
				string temp(n, '.');
				vector<string> temp_result(n, temp);
				for(int i = 0; i < row; ++i)
					temp_result[i][col[i]] = 'Q';
				result.push_back(temp_result);
				col[--row]++;
			} else if(col[row] == n){
				col[row--] = 0;
				if(row == -1)
					break;
				col[row]++;
			} else if(!isValid(col, row, col[row])){
				col[row]++;
			} else{
				row++;
			}
		}
       		return result; 
    	}
};

int main()
{
	Solution sol;
	vector<vector<string> > result = sol.solveNQueens(8);
	for(int i=0; i < result.size(); ++i){
		for(int j=0; j < result[i].size(); ++j)
			cout << result[i][j] << endl;
		cout << "#################" << endl;
	}
	cout << result.size() << endl;
	return 0;
}
