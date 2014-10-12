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
		vector<vector<string>> partition(string s) {
			vector<vector<string>> result;
			if(s.size() == 0){
				return result;
			}
			// partition_temp to store the each feasible partition
			vector<string> partition_temp;
			addPalindrome(s, 0, partition_temp, result);

			return result;
		}

		void addPalindrome(string &s, int start, vector<string> &partition_temp, vector<vector<string>> &result){
			// Stop condition
			if(start == s.size()){
				vector<string> temp(partition_temp.begin(), partition_temp.end());
				result.push_back(temp);
				return;
			}
			
			// DFS
			for(int i = start + 1; i <= s.size(); ++i)
			{
	//			cout << "i= " << i  << " start= " << start << "  ######################" << endl;
				string str = s.substr(start, i - start);	
	//			cout << str << endl;
				if(ispalidrome(str, 0, str.size()-1)){
					// Key 
					partition_temp.push_back(str);
					addPalindrome(s, i, partition_temp, result);
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

//	unordered_map<string, vector<vector<string>>> sub_problem;
	// Time Limited
/*	unordered_map<string, vector<string>> sub_problem;
	public:
		vector<vector<string>> partition(string s) {
			vector<string> non_repeat = get_partition(s);
			vector<vector<string>> result;
			vector<string> temp;
			for(int i = 0; i < non_repeat.size(); ++i)
			{
				temp = split(non_repeat[i], ' ');	
				if(temp.size() != 0)
					result.push_back(temp);
			}
			return result;
		}

		vector<string> split(string s, char gap){
			vector<string> result;
			if(s.size() == 0)
				return result;
			istringstream ins(s);
			string temp;
			while(ins.good())
			{
				getline(ins, temp, gap);	
				if(!temp.empty())
					result.push_back(temp);
			}
			return result;
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
		vector<string> get_partition(string s){
			vector<string> s_partition;
			if(s.size() == 0)
				return s_partition;
			if(ispalidrome(s, 0, s.size()-1)){
				s_partition.push_back(s);
			}
			if(s.size() == 1){
				sub_problem[s] = s_partition;
				return s_partition;
			}
			int n = s.size()-1;	
			while(n > 0)
			{
				string s1 = s.substr(0,n);
				string s2 = s.substr(n);
				auto after_iterator = sub_problem.find(s2);
				vector<string> after_str;
				if(after_iterator != sub_problem.end()){
					after_str = after_iterator->second;
				}else{
					after_str = get_partition(s2);
				}

				auto before_iterator = sub_problem.find(s1);
				vector<string> before_str;
				if(before_iterator != sub_problem.end()){
					before_str = before_iterator->second;
				}else{
					before_str = get_partition(s1);
				}

				for(int i = 0; i < before_str.size(); ++i)
				{
					for(int j = 0; j < after_str.size(); ++j)	
					{
						s_partition.push_back(before_str[i] + " " + after_str[j]);
					}
				}
				--n;
			}

			if(s_partition.size() != 0){
				set<string> temp(s_partition.begin(), s_partition.end());
				vector<string> s_partition_final(temp.begin(), temp.end());
				sub_problem[s] = s_partition_final;
				return s_partition_final;
			}
			return s_partition;
		}
*/
	// ¥Ê‘⁄÷ÿ∏¥
	/*
		vector<vector<string>> partition(string s) {
			vector<vector<string>> s_partition;
			if(s.size() == 0)
				return s_partition;
			if(ispalidrome(s, 0, s.size()-1)){
				vector<string> temp;
				temp.push_back(s);
				s_partition.push_back(temp);
			}
			if(s.size() == 1){
				sub_problem[s] = s_partition;
				return s_partition;
			}
			int n = s.size()-1;	
			while(n > 0)
			{
				string s1 = s.substr(0,n);
				string s2 = s.substr(n);
				auto after_iterator = sub_problem.find(s2);
				vector<vector<string>> after_str;
				if(after_iterator != sub_problem.end()){
					after_str = after_iterator->second;
				}else{
					after_str = partition(s2);
					sub_problem[s2] = after_str;
				}

				auto before_iterator = sub_problem.find(s1);
				vector<vector<string>> before_str;
				if(before_iterator != sub_problem.end()){
					before_str = before_iterator->second;
				}else{
					before_str = partition(s1);
					sub_problem[s1] = before_str;
				}

				for(int i = 0; i < before_str.size(); ++i)
				{
					for(int j = 0; j < after_str.size(); ++j)	
					{
						vector<string> temp = before_str[i];
						for(int k = 0; k < after_str[j].size(); ++k)
							temp.push_back(after_str[j][k]);
						s_partition.push_back(temp);
					}
				}
				--n;
			}

			if(s_partition.size() != 0){
				sub_problem[s] = s_partition;
			}
			return s_partition;
		}
		*/
};

int main()
{
//	string str =t "kwtbjmsjvbrwriqwxadwnufplszhqccayvdhhvscxjaqsrmrrqngmuvxnugdzjfxeihogzsdjtvdmkudckjoggltcuybddbjoizu";
	string str = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
//	string str = "aaaaa";
	Solution sol;
//	cout << sol.ispalidrome(str, 0, str.size()-1) << endl;
//	cout << str.substr(1, 2) << endl;
/*	vector<string> result = sol.get_partition(str);
	for(int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << endl;	
	}
	*/
	vector<vector<string>> result = sol.partition(str);
	for(int i = 0; i < result.size(); ++i)
	{
		for(int j = 0; j < result[i].size(); ++j)	
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}
