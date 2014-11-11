#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> dig2char;
		dig2char['2'] = "abc";
		dig2char['3'] = "def";
		dig2char['4'] = "ghi";
		dig2char['5'] = "jkl";
		dig2char['6'] = "mno";
		dig2char['7'] = "pqrs";
		dig2char['8'] = "tuv";
		dig2char['9'] = "wxyz";

		vector<string> result;
		if(digits.size() == 0){
			result.push_back("");
			return result;
		}
		vector<int> cols(digits.size(), 0);
		int row = 0;

		while(1){
			// Get a results.
			if(row == digits.size()){
				string temp_results;
				for(int i = 0; i < row; ++i)
					temp_results.push_back(dig2char[digits[i]][cols[i]]);
				result.push_back(temp_results);
				cols[--row]++;
			}else if(cols[row] == dig2char[digits[row]].size()){
				cols[row--] = 0;
				if(row == -1)
					break;
				cols[row]++;
			}else {
			    row++;
		    	}
	    	}
	    	return result;
    }
};

int main(){
	Solution sol;
	vector<string> result = sol.letterCombinations("23");
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;

	return 0;
}
