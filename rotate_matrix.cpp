#include <iostream>
#include <vector>

using namespace std;

class Solution {
//the key is to find the independent circle in the matrix
public:
	void rotate(vector<vector<int> > &matrix, int flag) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int n = matrix.size();
		for (int i = 0; i < n/2; ++i)
		{
			for (int j = i; j < n-1-i; ++j)
			{
				if(flag == 1){
					int tmp = matrix[i][j];
					matrix[i][j] = matrix[n-1-j][i];
					matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
					matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
					matrix[j][n-1-i] = tmp;
				}else{
					int tmp =  matrix[j][n-1-i];
					matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
					matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
					matrix[n-1-j][i] = matrix[i][j];
					matrix[i][j] = tmp;
				}
			}
		}
	}
};

int main()
{
	vector<vector<int>> matrix={{2,1}, {3,4}};
	for(int i=0;i<matrix.size(); ++i){
		for(int j=0;j<matrix[i].size(); ++j){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	Solution sol;
	sol.rotate(matrix, 0);
	for(int i=0;i<matrix.size(); ++i){
		for(int j=0;j<matrix[i].size(); ++j){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
