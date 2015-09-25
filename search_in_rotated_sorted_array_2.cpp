#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>

using namespace std;

class Solution {
	public:
		int getMidIndex(int min_index, int max_index, int length){
			if(min_index < max_index){
				return (min_index + max_index)/2;
			}else{
				int step = (max_index + length - min_index)/2 + 1;
				return (min_index + step)%length;
			}
		}
		bool search(vector<int>& nums, int target) {
			int max_index = 0;
			int max_num = -10000;
			int min_index = 0;
			int min_num = 10000;
			for(int i = 0 ; i < nums.size(); ++i){
				if(nums[i] > max_num){
					max_num = nums[i];
					max_index = i;
				}
				if(nums[i] < min_num){
					min_num = nums[i];
					min_index = i;
				}
			}
			if(target > max_num || target < min_num){
				return false;
			}
			while(max_index != min_index){
				int mid_index = getMidIndex(min_index, max_index, nums.size());
		//		cout << max_index << " " << min_index << " " << mid_index << endl;
				if(target == nums[mid_index]){
					return true;
				}else if (target < nums[mid_index]){
					int new_max_index = (mid_index - 1) >= 0 ? mid_index-1 : nums.size()-1;
					if(new_max_index == max_index){
						return false;
					}else{
						max_index = new_max_index;
					}
				}else{
					int new_min_index = (mid_index + 1) % nums.size();
					if(new_min_index == min_index){
						return false;
					}else{
						min_index = new_min_index;
					}
				}
			}
			if(nums[max_index] != target){
				return false;
			}else{
				return true;
			}
		}
};

int main()
{
//	vector<int> vec={4,5,6,0,1,2,3,3};
	vector<int> vec={3,5,1};
	Solution sol;
	cout << sol.search(vec, 4) << endl;
	return 0;
}
