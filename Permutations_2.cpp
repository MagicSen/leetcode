#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	/*
	bool isVaild(vector<int> col, int row, map<int,int> dict_map, vector<int> nums){
		for(int i = 0; i <= row; ++i){
			dict_map[nums[col[i]]]--;
			if(dict_map[nums[col[i]]] < 0)
				return false;
		}
		return true;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		map<int,int> dict_map;
		int length = nums.size();
		sort(nums.begin(), nums.end());
		vector<int> col(length, 0);
		set<vector<int>> result;
		for(int i = 0; i < length; ++i){
			if(dict_map.find(nums[i]) == dict_map.end())
				dict_map[nums[i]] = 0;
			dict_map[nums[i]] += 1;
		}
		int row = 0;
		while(1){
			// if row == length
			if(row == length){
				vector<int> temp(length, 0);
				for(int i = 0; i < length; ++i)
					temp[i] = nums[col[i]];
				result.insert(temp);
				col[--row] += 1;
			}else if(col[row] == length){
				col[row--] = 0;
				if(row == -1)
					break;
				col[row] += 1;
			}else if(!isVaild(col, row, dict_map, nums)){
				col[row] += 1;
			}else{
				row++;
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}
	*/
	vector<vector<int>> permuteUnique(vector<int> &nums){
		map<int, int> dict_map;
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int> temp;
		for(int i = 0; i < nums.size(); ++i){
			if(dict_map.find(nums[i]) == dict_map.end())
				dict_map[nums[i]] = 0;
			dict_map[nums[i]] += 1;
		}
		permuteUnique(result, temp, dict_map, nums.size());
		return result;
	}
	void permuteUnique(vector<vector<int>> &result, vector<int> &temp, map<int, int> &dict_map, int n){
		if(n == 0){
			result.push_back(temp);
			return;
		}
		// 递归采用map保存数字的重复程度
		for(auto &p:dict_map){
			if(p.second == 0 ) continue;
			p.second--;
			temp.push_back(p.first);
			permuteUnique(result, temp, dict_map, n-1);
			temp.pop_back();
			p.second++;
		}
	}
};
void printVector(vector<vector<int>> &matrix){
	for(int i = 0; i < matrix.size(); ++i){
		for(int j = 0; j <matrix[i].size(); ++j){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	vector<int> temp={-1,2,-1,2,1,-1,2,1};
	Solution sol;
	vector<vector<int>> result = sol.permuteUnique(temp);
	printVector(result);
	return 0;
}
