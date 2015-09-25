#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int profit = 0;
			if(prices.size() == 0)
				return profit;
			for(int i = 0; i < prices.size()-1; ++i){
				if(prices[i] < prices[i+1]){
					profit += prices[i+1] - prices[i];
				}
			}
			return profit;
		}
};

int main()
{
	vector<int> prices={1,2,3,4,4,4,5,6,7};	
	Solution sol;
	cout << sol.maxProfit(prices) << endl;
	return 0;
}
