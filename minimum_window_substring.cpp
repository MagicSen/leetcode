#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
	public:
		string minWindow(string s, string t) {
			unordered_map<char, int> t_dict;
			unordered_map<char, int> windows;
			if(s.size() == 0 || t.size() == 0){
				return "";
			}
			// 获得字符串t的全部信息
			for(int i = 0; i < t.size(); ++i){
				t_dict[t[i]]++;
			}
			int match_Length = 0;
			int min_length = INT_MAX;
			string result = "";
			for(int head = 0, tail = 0; head < s.size(); ++head){
				if( t_dict.find(s[head]) != t_dict.end()){
					windows[s[head]]++;
					if(windows[s[head]] <= t_dict[s[head]]){
						match_Length++;
					}
				}
				if(match_Length >= t.size()){
					while(t_dict.find(s[tail]) == t_dict.end() || windows[s[tail]] > t_dict[s[tail]]){
						windows[s[tail]]--;
						tail++;
					}
					if(head - tail + 1 < min_length){
						min_length = head - tail + 1;
						result = s.substr(tail, min_length);
					}
		//			cout << tail << " " << min_length << " " << s.substr(tail, min_length) << endl;
					windows[s[tail]]--;
					tail++;
					match_Length--;
				}
			}
			return result;
		}
};

int main()
{
	Solution sol;	
//	cout << sol.minWindow("absda", "ad") << endl;
	cout << sol.minWindow("ADOBECODEBANC", "ABC") << endl;
	return 0;
}
