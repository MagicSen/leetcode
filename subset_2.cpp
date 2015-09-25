#include<iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int> > total_set = {{}};
			sort(nums.begin(), nums.end());
			for(int i = 0; i < nums.size();){
				int count = 0;
				while(count + i < nums.size() && nums[i] == nums[count+i])
					count++;
				int pre_num = total_set.size();
				for(int k = 0; k < pre_num; ++k ){
					vector<int> sub_set = total_set[k];
					for(int j = 0; j < count; ++j){
						sub_set.push_back(nums[i]);
						total_set.push_back(sub_set);
					}
				}
				i += count;
			}
			return total_set;
		}
};

int main()
{
	vector<int> element={1,2,2,3};	
	Solution sol;
	vector<vector<int>> sub_set = sol.subsetsWithDup(element);
	for(int i = 0; i < sub_set.size(); ++i){
		for(int j = 0; j < sub_set[i].size(); ++j){
			cout << sub_set[i][j] << " ";
		}
		cout << endl;
	}
}
