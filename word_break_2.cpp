#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <set>

using namespace std;

class Solution {
	private:
		unordered_map<string, vector<string>> subproblem;
	public:
		vector<string> word_break(string s, unordered_set<string> &dict)
		{

			vector<string> sub_string;
			if(s.size() == 0)
				return sub_string;

			auto temp_iter = subproblem.find(s);
			auto temp_dict_iter = dict.find(s);
			
			if(temp_iter != subproblem.end()){
				return temp_iter->second;
			}
			if(temp_dict_iter != dict.end()){
				sub_string.push_back(s);
			}

			int i = s.size()-1;	
			while(i >= 0)
			{

				auto temp_before_iter = subproblem.find(s.substr(0,i));
				auto temp_after_iter = subproblem.find(s.substr(i));
				auto temp_i_iter = dict.find(s.substr(i));

				if(temp_before_iter != subproblem.end() && temp_after_iter != subproblem.end()){
					for(int i = 0; i < (temp_before_iter->second).size(); ++i)
					{
						for(int j = 0; j < (temp_after_iter->second).size(); ++j)
						{
							sub_string.push_back( (temp_before_iter->second)[i] + " " + (temp_after_iter->second)[j]);	
						}
					}
				}else{
					if(temp_after_iter != subproblem.end()){
						vector<string> sub_string_2 = word_break(s.substr(0,i), dict);
						for(int i = 0; i < sub_string_2.size(); ++i)
						{
							for(int j = 0; j < (temp_after_iter->second).size(); ++j)
							{
								sub_string.push_back(sub_string_2[i] + " " + (temp_after_iter->second)[j]);
							}
						}

						if(sub_string_2.size() != 0){
							subproblem[s.substr(0,i)] = sub_string_2;
						}
					}else{
						if(temp_i_iter != dict.end()){
							vector<string> temp;
							temp.push_back(*temp_i_iter);
							subproblem[s.substr(i)] = temp;
							vector<string> sub_string_2 = word_break(s.substr(0,i), dict);
							for(int i = 0; i < sub_string_2.size(); ++i)
							{
								sub_string.push_back(sub_string_2[i] + " " + *temp_i_iter);
							}
							if(sub_string_2.size() != 0){
								subproblem[s.substr(0,i)] = sub_string_2;
							}
						}
					}
				}
				--i;
			}
			if(sub_string.size() != 0){
				subproblem[s] = sub_string;
			}
			return sub_string;
		}
		vector<string> wordBreak(string s, unordered_set<string> &dict) {
			// remove the repeat strings.
			vector<string> temp = word_break(s, dict);
			set<string> temp_set(temp.begin(), temp.end());
			vector<string> final_string(temp_set.begin(), temp_set.end());
			return final_string;
		}
	// dynamic plan, has repeat
	/*
	private:
		unordered_map<string, vector<string>> subproblem;
	public:
		vector<string> word_break(string s, unordered_set<string> &dict)
		{

			vector<string> sub_string;
			if(s.size() == 0)
				return sub_string;

			auto temp_iter = subproblem.find(s);
			auto temp_dict_iter = dict.find(s);
			
			if(temp_iter != subproblem.end()){
				return temp_iter->second;
			}
			if(temp_dict_iter != dict.end()){
				sub_string.push_back(s);
			}

			int i = s.size()-1;	
			while(i >= 0)
			{

				auto temp_before_iter = subproblem.find(s.substr(0,i));
				auto temp_after_iter = subproblem.find(s.substr(i));
				auto temp_i_iter = dict.find(s.substr(i));

				if(temp_before_iter != subproblem.end() && temp_after_iter != subproblem.end()){
					for(int i = 0; i < (temp_before_iter->second).size(); ++i)
					{
						for(int j = 0; j < (temp_after_iter->second).size(); ++j)
						{
							sub_string.push_back( (temp_before_iter->second)[i] + " " + (temp_after_iter->second)[j]);	
						}
					}
				}else{
					if(temp_after_iter != subproblem.end()){
						vector<string> sub_string_2 = word_break(s.substr(0,i), dict);
						for(int i = 0; i < sub_string_2.size(); ++i)
						{
							for(int j = 0; j < (temp_after_iter->second).size(); ++j)
							{
								sub_string.push_back(sub_string_2[i] + " " + (temp_after_iter->second)[j]);
							}
						}

						if(sub_string_2.size() != 0){
							subproblem[s.substr(0,i)] = sub_string_2;
						}
					}else{
						if(temp_i_iter != dict.end()){
							vector<string> temp;
							temp.push_back(*temp_i_iter);
							subproblem[s.substr(i)] = temp;
							vector<string> sub_string_2 = word_break(s.substr(0,i), dict);
							for(int i = 0; i < sub_string_2.size(); ++i)
							{
								sub_string.push_back(sub_string_2[i] + " " + *temp_i_iter);
							}
							if(sub_string_2.size() != 0){
								subproblem[s.substr(0,i)] = sub_string_2;
							}
						}
					}
				}
				--i;
			}
			if(sub_string.size() != 0){
				subproblem[s] = sub_string;
			}
			return sub_string;
		}
		vector<string> wordBreak(string s, unordered_set<string> &dict) {
			return word_break(s, dict);
		}
		*/

};

int main()
{
	unordered_set<string> dict{"a", "abc","b","cd","d","c","ab"};
	string s = "abcd";
	Solution sol;
	//	cout << sol.wordBreak(s, dict)<< endl;
	vector<string> temp = sol.wordBreak(s, dict);
	for(auto i:temp)
		cout << i << endl;
	return 0;
}
