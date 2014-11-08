#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
	// Store the result to avoid repeat caculating.
	int store_result[101][101];
public:
	Solution(){
		for(int i = 0; i < 101; ++i)
			for(int j = 0; j < 101; ++j)
				store_result[i][j] = 0;
	}
	int uniquePaths(int m, int n) {
		if(m == 1 || n == 1)
			return 1;
		int left_paths = store_result[m-1][n];
		int above_paths = store_result[m][n-1];
		if( left_paths != 0 && above_paths != 0){
			store_result[m][n] = left_paths + above_paths;
		}else if(left_paths != 0){
			store_result[m][n] = left_paths + uniquePaths(m,n-1);
		}else if(above_paths != 0){
			store_result[m][n] = uniquePaths(m-1,n) + above_paths;
		}else{
			store_result[m][n] = uniquePaths(m-1,n) + uniquePaths(m,n-1);
		}
		return store_result[m][n];
	}

};

int main()
{
	Solution sol;
	cout << sol.uniquePaths(2,3) << endl;
	return 0;
}
