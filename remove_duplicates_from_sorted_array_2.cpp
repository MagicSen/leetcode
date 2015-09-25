#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>

using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int length = nums.size();
			int p = 0;
			int q = 0;
			while(q < nums.size()){
				if(nums[q] != nums[p]){
					length = length - max(0, q-p-2);
					if(q - p > 2){
						vector<int>::iterator temp = nums.erase(nums.begin()+p+2, nums.begin()+q);
						p = temp - nums.begin();
						q = p;
					}else{
						p = q;
					}
				}else{
					q++;
				}
			}
			length = length - max(0, q-p-2);
			if(q - p > 2){
				vector<int>::iterator temp = nums.erase(nums.begin()+p+2, nums.begin()+q);
			}
			return length;
		}
};

int main()
{
//	vector<int> vec={1,1,1,1,2,2,3,4,4,4,5,6,6,6,7};
	vector<int> vec={1,1,1,1};
	Solution sol;
	cout << sol.removeDuplicates(vec) << endl;
	for(int i = 0 ; i< vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}
