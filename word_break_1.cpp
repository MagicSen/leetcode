#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
	// dynamic plan
	private:
		unordered_set<string> subproblem;
	public:
		bool word_break(string s, unordered_set<string> &dict, int max_dict_words)
		{
			if(s.size() == 0)
				return true;
			int i = s.size()-1;	
			while(i >= 0)
			{
				if(subproblem.find(s) != subproblem.end()){
					return true;
				}else if(subproblem.find(s.substr(0,i)) != subproblem.end() && subproblem.find(s.substr(i)) != subproblem.end()){
					subproblem.insert(s);
					return true;
				}else{
					if(subproblem.find(s.substr(i)) != subproblem.end() || dict.find(s.substr(i)) != dict.end()){
							subproblem.insert(s.substr(i));
							if(word_break(s.substr(0,i), dict, max_dict_words))
								return true;
							else
								--i;
					}else{
						--i;
					}
				}
			}
			return false;
		}
		bool wordBreak(string s, unordered_set<string> &dict) {
			if(s.size() == 0) 
				return false;
			else{
				int max_dict_words = 0;
				for(auto i : dict)
				{
					if(i.size() > max_dict_words)	
						max_dict_words = i.size();
				}
				return word_break(s, dict, max_dict_words);
			}
		}
		/*	
		// Time limited
		bool word_break(string s, unordered_set<string> &dict, int max_dict_words)
		{
		if(s.size() == 0)
		return true;
		int i = 1;	
		vector<int> i_matches;
		while(i <= max_dict_words && i <= s.size())
		{
		if(dict.find(s.substr(0,i)) != dict.end()){
		i_matches.push_back(i);
		}
		++i;
		}
		if(i_matches.size() == 0)
		return false;
		else{
		sort(i_matches.begin(), i_matches.end());
		for(int i = i_matches.size()-1; i >= 0; --i){
		if(word_break(s.substr(i_matches[i]), dict, max_dict_words))
		return true;
		}
		return false;
		}
		}

		bool wordBreak(string s, unordered_set<string> &dict) {
		if(s.size() == 0) 
		return false;
		else{
		int max_dict_words = 0;
		for(auto i : dict)
		{
		if(i.size() > max_dict_words)	
		max_dict_words = i.size();
		}
		return word_break(s, dict, max_dict_words);
		}
		}
		*/

};

int main()
{
	unordered_set<string> dict{"a", "abc","b","cd"};
	string s = "abcd";
	Solution sol;
	cout << sol.wordBreak(s, dict)<< endl;
	return 0;
}
