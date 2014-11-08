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
	int totalNQueens(int n) {
		vector<int> col(n, 0);
		int row = 0;
		int total = 0;
		while(1){
			if(row == n){
				total++;
				col[row--] = 0;
				col[row]++;
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
	}
};

int main()
{
	Solution sol;
	cout << sol.totalNQueens(8) << endl;
	return 0;
}
