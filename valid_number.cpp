#include <iostream>
#include <vector>
#include <algorithM>
#include <regex>

using namespace std;


class Solution {
	public:
		void clearBlack(string &s){
			if(s.size() == 0){
				return;
			}
			while(s[0] == ' '){
				s.erase(0, 1);
			}
			int len = s.size();
			while(len > 0 && s[len-1] == ' '){
				s.erase(len-1, 1);
				len = len-1;
			}
		}
		bool isAvailable(string &s, int &e_index){
			string available_string = "eE.0123456789+-";
			int e_flag = 0;
			for(int i = 0; i < s.size(); ++i){
				if(available_string.find(s[i]) == string::npos){
					return false;
				}else{
					if(available_string.find(s[i]) == 0 || available_string.find(s[i]) == 1){
						s[i] = 'e';
						e_flag++;
						e_index = i;
					}
					if(e_flag > 1){
						return false;
					}
				}
			}
			return true;
		}
		bool isDecimal(string &s, int type){
			string num_str = "0123456789";
			if(s.size() == 0){
				return false;
			}
			int flag_digital = 0;
			for(int i = 0 ; i< s.size(); ++i){
				if((s[i] == '+' || s[i] == '-')){
					if(i == 0 && i != s.size()-1)
						continue;
					else
						return false;
				}
				if(s[i] == '.'){
					if(type == 1){
						return false;
					}
					flag_digital++;
				        if(flag_digital > 1)
				               return false;
				        else if((i == 0 && i != s.size()-1 && num_str.find(s[i+1]) != string::npos) || (i != 0 && i == s.size()-1 && num_str.find(s[i-1]) != string::npos) || num_str.find(s[i-1]) != string::npos || num_str.find(s[i+1]) != string::npos)
					       continue;
				       else
					       return false;
				}
				if(num_str.find(s[i]) == string::npos){
					return false;
				}
			}
			return true;
		}
		bool isNumber(string s) {
			clearBlack(s);				
			int e_index = -1;
			if(isAvailable(s, e_index)){
				if(e_index != -1){
					string s1 = s.substr(0,e_index);
					string s2 = s.substr(e_index+1);
					return isDecimal(s1, 0) && isDecimal(s2, 1);
				}else{
					return isDecimal(s,0);
				}
			}
			return false;
		}
};

/*
int main()
{

}
*/
template <typename T>
std::string regexCode (T code)
{
    switch (code) {
        case std::regex_constants::error_collate:
               return "error_collate: regex has invalid collating element name";
        case std::regex_constants::error_ctype:
               return "error_ctype: regex has invalid character class name";
        case std::regex_constants::error_escape:
               return "error_escape: regex has invalid escaped char. or trailing escape";
        case std::regex_constants::error_backref:
               return "error_backref: regex has invalid back reference";
        case std::regex_constants::error_brack:
               return "error_brack: regex has mismatched ¡¯[¡¯ and ¡¯]¡¯";
        case std::regex_constants::error_paren:
               return "error_paren: regex has mismatched ¡¯(¡¯ and ¡¯)¡¯";
        case std::regex_constants::error_brace:
               return "error_brace: regex has mismatched ¡¯{¡¯ and ¡¯}¡¯";
        case std::regex_constants::error_badbrace:
               return "error_badbrace: regex has invalid range in {} expression";
        case std::regex_constants::error_range:
               return "error_range: regex has invalid character range, such as ¡¯[b-a]¡¯";
        case std::regex_constants::error_space:
               return "error_space: insufficient memory to convert regex into finite state";
        case std::regex_constants::error_badrepeat:
               return "error_badrepeat: one of *?+{ not preceded by valid regex";
        case std::regex_constants::error_complexity:
               return "error_complexity: complexity of match against regex over pre-set level";
        case std::regex_constants::error_stack:
               return "error_stack: insufficient memory to determine regex match";
    }
    return "unknown/non-standard regex error code";
}

int main()
{
    try {
	Solution sol;
	cout << sol.isNumber(" 1eE23123  ") << endl;
	cout << sol.isNumber(" 12 3  ") << endl;
	cout << sol.isNumber(" e  ") << endl;
	cout << sol.isNumber(" 12e3  ") << endl;
	cout << sol.isNumber(" .1  ") << endl;
	cout << sol.isNumber(" 1.1  ") << endl;
	cout << sol.isNumber(" 1.  ") << endl;
	cout << sol.isNumber(" .  ") << endl;
	cout << sol.isNumber(" +12e3  ") << endl;
	cout << sol.isNumber(" +1.2e3  ") << endl;
	cout << sol.isNumber(" +1.2e+3  ") << endl;
	cout << sol.isNumber(" +1.2e+  ") << endl;
	cout << sol.isNumber(" +1.2e6.5  ") << endl;
    }
    catch (const regex_error& e) {
        cerr << "regex_error: \n"
              << " what(): " << e.what() << "\n"
              << " code(): " << regexCode(e.code()) << endl;
    }
}
