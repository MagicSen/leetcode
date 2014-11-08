#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> grayCode(int n) {
			vector<int> result(1, 0);
			for(int i = 0; i < n; ++i){
				int curCount = result.size();
				while(curCount){
					curCount--;
					int curNum = result[curCount];
					curNum += (1<<i);
					result.push_back(curNum);
				}
			}
			return result;
		}

};

int main()
{
	Solution sol;
	vector<int> result = sol.grayCode(5);
	for(int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;	
	}
	return 0;
}
