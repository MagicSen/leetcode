#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
		void rotate(vector<vector<int>>& matrix) {
			int length = matrix.size();
			if(length == 0)
				return;
			for(int k = 0; k < length/2; ++k){
				for(int i = 0; i < length-1-2*k; ++i){
					int x = 0;
					int y = i;
					int begin_value = matrix[x+k][y+k];
					int end_value = 0;
					cout << k << ":\t";
					for(int j = 0; j < 4; ++j){
						cout << x+k << " - " << y+k << ",";
						int temp = x;
						x = y;
						// Each time cut double k
						y = length - 1 - 2*k - temp;
						end_value = matrix[x+k][y+k];
						matrix[x+k][y+k] = begin_value;
						begin_value = end_value;
					}
					cout <<endl;
				}
			}
		}
		void printVector(vector<vector<int>> &matrix){
			for(int i = 0; i < matrix.size(); ++i){
				for(int j = 0; j <matrix[i].size(); ++j){
					cout << matrix[i][j] << " ";
				}
				cout << endl;
			}
		}
};

int main()
{
	vector<vector<int>> vec = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
//	vector<vector<int>> vec = {{1,2,3}, {4,5,6}, {7,8,9}};
	Solution sol;
	sol.printVector(vec);
	sol.rotate(vec);
	sol.printVector(vec);
	return 0;
}
