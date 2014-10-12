#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
	public:
		// DFS 
	    	int minCut(string s) {
			int min_Cut = s.size();
			if(s.size() == 0 || s.size() == 1){
				return min_Cut;
			}
			vector<string> partition_temp;
			addPalindrome(s, 0, partition_temp, min_Cut);
			return min_Cut;
    		}

		void addPalindrome(string &s, int start, vector<string> &partition_temp, int &min_Cut){
			// Stop condition
			if(start == s.size()){
				min_Cut = partition_temp.size();
				return;
			}
			// DFS
			for(int i = start + 1; i <= s.size(); ++i)
			{
				if(partition_temp.size() >= min_Cut)
					return;
				string str = s.substr(start, i - start);	
				if(ispalidrome(str, 0, str.size()-1)){
					// Key 
					partition_temp.push_back(str);
					addPalindrome(s, i, partition_temp, min_Cut);
					partition_temp.erase(partition_temp.begin() + partition_temp.size()-1);
				}
			}
		}

		bool ispalidrome(const string str, int begin, int end){
			if(str.size() == 1)
				return true;
			if(str.size() == 0)
				return false;
			while(begin < end)
			{
				if(str[begin] != str[end])	
					return false;
				begin++;
				end--;
			}
			return true;
		}
};

int main()
{
//	string str = "kwtbjmsjvbrwriqwxadwnufplszhqccayvdhhvscxjaqsrmrrqngmuvxnugdzjfxeihogzsdjtvdmkudckjoggltcuybddbjoizu";
	string str = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
//	string str = "aaaaa";
	Solution sol;
	cout << "str.length = " << str.size() << endl;
	cout << sol.minCut(str) << endl;
/*	vector<vector<string>> result = sol.partition(str);
	for(int i = 0; i < result.size(); ++i)
	{
		for(int j = 0; j < result[i].size(); ++j)	
			cout << result[i][j] << " ";
		cout << endl;
	}
	*/
	return 0;
}
