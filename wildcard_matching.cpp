#include <iostream>
#include <string>

using namespace std;

class Solution {
	public:
		bool isMatch(const char *s, const char *p) {
			const char* star = NULL;
			const char* ss=s;
			while (*s){
				if((*p == '?') || (*p == *s)){
					s++;
					p++;
					continue;
				}
				// * found in pattern, track index of *, only advancing pattern pointer.
				if(*p == '*' ){
					star=p++;
					ss = s;
					continue;
				}

				// If didn't match, and last pattern pointer was *, only advancing pattern pointer
				if(star){
					p = star+1;
					s = ++ss;
					continue;
				}
				
				return false;
			}
			while(*p == '*'){p++;}

			return !(*p);
		}
/*		bool isMatch(const string s, const string p){
			int i = 0;
			int j = 0;
			while(i != s.size() && j != p.size())
			{
				if(p[j] != '*'){
					if(p[j] != '?'){
						if(p[j] == s[i]){
							++j;
							++i;
						} else{
							return false;
						}
					}else {
						++j;
						++i;
					}
				}else {
					if(j == p.size() - 1 )
						return true;
					else
						return isMatch(s.substr(i), p.substr(j+1));
				}
			}

			if(j == p.size() && i == s.size())
				return true;
			else{
				if(i == s.size()){
					for(;j < p.size(); ++j)
						if(p[j] == '*')
							continue;
						else 
							return false;
					return true;
				}
				return false;
			}
		}
		bool isMatch(const char *s, const char *p) {
			const string s_str(s);
			const string p_str(p);
			return isMatch(s_str, p_str);

		}
*/
};

int main()
{
	Solution sol;
	cout << sol.isMatch("hi", "*?") << endl;
	return 0;
}
