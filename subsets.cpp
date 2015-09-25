#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			int num_subset = pow(2, nums.size());
			vector<vector<int>> result(num_subset, vector<int>);
			for(int i = 0; i < nums.size(); ++i){
				for(int j = 0; j < num_subset; ++j){
					if(j >> i & 1){
						result[j].push_back(nums[i]);
					}
				}
			}
			return result;
		}
};

int main()
{
	Solution sol;
	return 0;
}
