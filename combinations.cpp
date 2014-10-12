#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
	// C(n,k) = C(n-1,k-1) + C(n-1, k)
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;      
		if(k == 1){
			for(int i = k; i <= n; ++i)
			{
				vector<int> temp;	
				temp.push_back(i);
				result.push_back(temp);
			}
			return result;
		}
		if(n < k)
			return result;
		if(n == k){
			vector<int> temp;
			for(int i = 1; i <=n; ++i)
				temp.push_back(i);
			result.push_back(temp);
			return result;
		}

		vector<vector<int>> temp = combine(n-1, k);
		for(int j = 0; j < temp.size(); ++j)
		{
			result.push_back(temp[j]);
		}
		temp = combine(n-1, k-1);
		for(int j = 0; j < temp.size(); ++j)
		{
			temp[j].push_back(n);
			result.push_back(temp[j]);
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<vector<int> > result = sol.combine(10,5);
	for(int i = 0; i < result.size(); ++i)
	{
		for(int j = 0; j < result[i].size(); ++j)	
			cout << result[i][j] << " ";
		cout << endl;
	}
	cout << result.size() << endl;
	return 0;
}
