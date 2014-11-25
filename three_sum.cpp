#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
		// Others
    vector<vector<int> > threeSum(vector<int> &num) {
		set<vector<int> > result;
		if(num.size() < 3)		
			return vector<vector<int>>(result.begin(), result.end());
		sort(num.begin(), num.end());
		vector<int> avail_result;
		int n = num.size();
		// Why ? this can be? because the former combination has been found.
		for(int i = 0; i < n-2; ++i)
		{
			if(i > 0 && num[i] == num[i-1])	
					continue;
			int j = i + 1;
			int k = num.size()-1;
			while(j < k){
					int sum = num[j] + num[k] + num[i];
					if(sum > 0){
							k--;
					}else if(sum < 0){
							j++;
					}else{
						avail_result.push_back(num[i]);
						avail_result.push_back(num[j]);
						avail_result.push_back(num[k]);
						result.insert(avail_result);
						avail_result.clear();
						k--;
						j++;
					}
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
	}

	vector<int> arrangeNum(const int &a,const int &b,const int &c){
			vector<int> avail_result;
			if(c < a){
					avail_result.push_back(c);
					avail_result.push_back(a);
					avail_result.push_back(b);
			}else if(c > b){
					avail_result.push_back(a);
					avail_result.push_back(b);
					avail_result.push_back(c);
			}else{
					avail_result.push_back(a);
					avail_result.push_back(c);
					avail_result.push_back(b);
			}
			return avail_result;
	}
	// Time limited
 /*   vector<vector<int> > threeSum(vector<int> &num) {
		set<vector<int> > result;
		set<int> dict;
		if(num.size() < 3)		
			return vector<vector<int>>(result.begin(), result.end());
		sort(num.begin(), num.end());
		for(int i = 0; i < num.size(); ++i)
		{
			if(dict.find(num[i]) == dict.end()){
					dict.insert(num[i]);
			}else{
					continue;
			}
			vector<int> temp = num;
			// a + b = -c
			temp.erase((temp.begin() + i));
			int j = 0;
			int k = temp.size()-1;
			while(j < k){
					if(temp[j] + temp[k] > -num[i]){
							k--;
					}else if(temp[j] + temp[k] < -num[i]){
							j++;
					}else{
						result.insert(arrangeNum(temp[j], temp[k], num[i]));
						k--;
					}
			}
		}
		return vector<vector<int>>(result.begin(), result.end());
    }
	*/
};

int main()
{
	Solution sol;
//	vector<int> num = {2,-1,1,0,-1,-2};
	vector<int> num = {0, 0, 0};
//	vector<int> num = {-1 , 0 , 1, 2, -1, -4};
//	vector<int> num = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
//	vector<int> num = {4,-10,-11,-12,-8,-12,-14,-11,-6,2,-4,2,3,12,-3,-12,-14,-12,-8,-9,-6,-3,10,2,14,10,7,-7,-9,0,-9,10,-2,-5,14,5,-9,7,9,0,-14,12,10,4,9,-8,8,11,-5,-15,-13,-3,-11,4,14,11,-1,-2,-11,5,14,-4,-8,-3,6,-9,9,12,6,3,-10,7,0,-15,-3,-13,-8,12,13,-5,12,-15,7,8,-4,-2,4,2,3,9,-8,2,-10,-1,6,3,-2,0,-7,11,-12,-2,3,-4,-2,7,-2,-3,4,-12,-1,1,10,13,-5,-9,-12,6,8,7,0,7,-6,5,13,8,-14,-12};
//	vector<int> num = {13,5,-4,-9,1,-3,10,-7,7,3,1,-13,-11,7,-10,12,-15,13,5,-8,-11,-12,-15,-13,-3,-13,5,-4,6,1,-10,4,13,-7,3,-9,-3,-2,-1,12,9,-15,14,5,0,-10,-5,-8,-12,-15,-1,-8,11,-9,-14,-7,-6,7,-4,-15,-15,-7,-4,14,1,6,12,14,12,-11,11,-2,11,2,-12,-4,7,-2,-5,10,-9,10,9,-13,-14,11,-13,-13,3,-1,9,3,7,-9,-6,-14,4,-8,7,1,-12,-5,14,14,12,10,-12,-3,-7,-2,-8,-9,-7,9,-7,-13,5,-12,-11,-7,2,14,3,-14};
	vector<vector<int>> result = sol.threeSum(num);
	for(int i = 0; i < result.size(); ++i){
			for(int j = 0; j < result[i].size(); ++j)
					cout << result[i][j] << " ";
			cout << endl;
	}
	return 0;
}
