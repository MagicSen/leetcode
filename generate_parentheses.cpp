#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool valid(vector<int> &cols, int &row, vector<int> &signal){
		int total = 0;
		int left = 0;
		for(int i = 0; i <= row; ++i){
			total += signal[cols[i]];
			if(signal[cols[i]] > 0)
				left++;
			if(left > cols.size() / 2)
				return false;
		}
		if(total >= 0)
			return true;
		else
			return false;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> result;
		vector<int> cols(n*2, 0);
		vector<int> signal{1,-1};
		int row = 0;

		while(1){
			if(row == 2*n){
				string temp(2*n, '(');
				for(int i = 0; i < 2*n; ++i)
					if(signal[cols[i]] < 0)
						temp[i] = ')';
				result.push_back(temp);
				cols[--row]++;
			}else if(cols[row] == 2){
				cols[row--] = 0;
				if(row == -1)
					break;
				cols[row]++;
			}else if(!valid(cols, row, signal)){
				cols[row]++;
			}else{
				row++;
			}
		}
		return result;
	}
};

int main()
{
	Solution sol;
	vector<string> result = sol.generateParenthesis(4);
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
