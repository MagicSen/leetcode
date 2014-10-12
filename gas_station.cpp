#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
	// Accept, Time is 16ms
	public:
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			vector<int> residue(gas.size(), 0);
			for(int i = 0; i < gas.size(); ++i)
			{
				residue[i] = gas[i] - cost[i];
			}
			for(int i = 0; i < residue.size(); ++i){
				int total = 0;
				for(int j = i; j < i + residue.size(); ++j)
				{
					total += residue[j % residue.size()];
					if(total < 0){
						if(j < residue.size()){
							i = j;
							break;	
						}else{
							return -1;
						}
					}
				}
				if(total >= 0)
					return i;
			}
			return -1;
		}
		// Accept , but time is 864ms
	/*	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
			vector<int> residue(gas.size(), 0);
			for(int i = 0; i < gas.size(); ++i)
			{
				residue[i] = gas[i] - cost[i];
			}
			for(int i = 0; i < residue.size(); ++i){
				int total = 0;
				for(int j = i; j < i + residue.size(); ++j)
				{
					total += residue[j % residue.size()];
					if(total < 0){
						break;	
					}
				}
				if(total >= 0)
					return i;
			}
			return -1;
		}
		*/
};

int main()
{
	vector<int> gas = {1, 2, 3, 4, 5};
	vector<int> cost = {5, 4, 3, 2, 1};
	Solution sol;
	cout << sol.canCompleteCircuit(gas, cost) << endl;
	return 0;
}
