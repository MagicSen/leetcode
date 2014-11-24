#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
	set<string> dict;
public:
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, int> dict;
		string s;
		vector<string> res;

		for(int i = 0; i < strs.size(); ++i){
			s = strs[i];
			sort(s.begin(), s.end());
			if(dict.find(s) == dict.end()){
				dict[s] = i;
			}else{
				if(dict[s] >= 0){
					res.push_back(strs[dict[s]]);
					dict[s] = -1;
				}
				res.push_back(strs[i]);
			}
		}
		return res;
	}
	
	// Misunderstood, think it is the reverse string
/*	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string,string> result;
		for(int i = 0; i < strs.size(); ++i)	
		{
			if(dict.find(string(strs[i].rbegin(), strs[i].rend())) != dict.end()){
				if(result.find(strs[i]) == result.end() && result.find(string(strs[i].rbegin(), strs[i].rend())) == result.end()){
					result[strs[i]] = string(strs[i].rbegin(), strs[i].rend());
				}
			}
			if(dict.find(strs[i]) == dict.end()){
				dict.insert(strs[i]);
			}
		}
		vector<string> final_result;
		for(auto i=result.begin(); i != result.end(); ++i)
		{
			final_result.push_back((*i).first);
			final_result.push_back((*i).second);
		}
		return final_result;
	}
	*/
};
int main()
{
	Solution sol;
	vector<string> test={"dog","cat","god","tac","ass"};
//	vector<string> test={"",""};
	cout << test.size() << endl;
	vector<string> result = sol.anagrams(test);
	cout << result.size() << endl;
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}
