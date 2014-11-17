#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Solution {
//	map<string, int> dict;
	public:
		// DFS 
/*	    	int minCut(string s) {
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
*/
	    int minCut(string s) {
		    if(s.empty())
			    return 0;
		    int n = s.size();
		    vector<vector<bool>> pal(n, vector<bool>(n, false));
		    vector<int> d(n);

		    for(int i = n-1; i >= 0; --i)
		    {
		   	d[i] = n-i-1;
			for(int j = i; j < n; ++j)
			{
				if(s[i] == s[j] && (j-i < 2 || pal[i+1][j-1])){
					pal[i][j] = true;
					if(j == n-1)
						d[i] = 0;
					else if(d[j+1]+1 < d[i])
						d[i] = d[j+1] + 1;
				}	
			}
		    }
		    return d[0];
	    }
		// Time limited
/*
	    int minCut(string s) {
		vector<vector<int>> dict(s.size(), vector<int>(s.size(), 0));
		if(ispalidrome(s, 0, s.size()-1))
			return 0;
		for(int k = 2; k <= s.size(); k++){
			for(int i = 0; i <= s.size()-k; ++i){
				if(ispalidrome(s, i, i+k-1)){
					dict[k-1][i] = 0;
				}else{
					int min_num = k;
					for(int j = k-1; j >= 1 ; --j){
						if(min_num > 1 + dict[j-1][i] + dict[k-j-1][i+j])
							min_num = 1 + dict[j-1][i] + dict[k-j-1][i+j];
					}
					dict[k-1][i] = min_num;
				}
			}
		}
		return dict[s.size()-1][0];
	    }
	    */
	// Recursion version
	    /*	int minCut(string s) {
			if(ispalidrome(s, 0, s.size()-1))
				return 0;
			int min_num = s.size()-1;
			for(int i = 1; i < s.size(); ++i){
				string s_nk = s.substr(0, i);
				string s_k = s.substr(i, s.size());
				if(dict.find(s_nk) == dict.end()){
					dict[s_nk] = minCut(s_nk);
				}
				if(dict.find(s_k) == dict.end()){
					dict[s_k] = minCut(s_k);
				}
				if(dict[s_nk] + dict[s_k] + 1 < min_num){
					min_num = dict[s_nk] + dict[s_k] + 1;
				}
			}
			return min_num;
		}
*/
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
	//	string str = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
	string str = "ltsqjodzeriqdtyewsrpfscozbyrpidadvsmlylqrviuqiynbscgmhulkvdzdicgdwvquigoepiwxjlydogpxdahyfhdnljshgjeprsvgctgnfgqtnfsqizonirdtcvblehcwbzedsmrxtjsipkyxk";
//		string str = "aaaaab";
	//	string str = "abab";
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
