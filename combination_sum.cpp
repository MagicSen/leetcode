#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	// Judge whether the sum is equal to target
	int isEqual(vector<int> &candidates, vector<int> choosen_num, int row, int target){
		int total = 0;
		for(int i = 0; i <= row; ++i)
			total += candidates[choosen_num[i]];
		if(total == target)
			return 0;
		else if(total < target)
			return 1;
		else 
			return -1;
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Sort the candidates, at first.
		sort(candidates.begin(), candidates.end());
		vector<int> choosen_num(target / candidates[0] + 1, 0);
		int row = 0;
		int col_max = candidates.size();
		vector<vector<int> > result;

		while(1){
			// Backtracking 
			// Cols must smaller than candidates's max cols.
			if(choosen_num[row] == col_max){
				row--;
				if(row == -1)
					break;
				choosen_num[row]++;
			}else{
				int flag = isEqual(candidates, choosen_num, row, target);
				if(flag == 1){
					choosen_num[row+1] = choosen_num[row];
					row++;
				}else if( flag == 0){
					vector<int> temp_result;
					for(int i = 0; i <= row; ++i)
						temp_result.push_back(candidates[choosen_num[i]]);
					result.push_back(temp_result);
					row--;
					if(row == -1)
						break;
					choosen_num[row]++;
				} else{
					row--;
					if(row == -1)
						break;
					choosen_num[row]++;
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<int> vec{4,3,2,1};
	Solution sol;
	vector<vector<int> > result = sol.combinationSum(vec, 7);
	for(int i=0; i<result.size(); ++i){
		for(int j=0; j<result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl << "************" << endl;
	}

	return 0;
}
