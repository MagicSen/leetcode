#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
	public:
		void tolower(string &s){
			for(int i = 0; i < s.size(); ++i)
			{
				if(s[i] >= 'A' && s[i] <= 'Z'){
					s[i] = s[i] - 'A' + 'a';
				}
			}
		}
		bool isvalid(char ch)
		{
			if((ch < 'a' || ch > 'z') && (ch < '0' || ch > '9'))	
				return false;
			else
				return true;
		}
		bool isPalindrome(string s) {
			if(s.size() == 0)
				return true;
			tolower(s);
			int i = 0;
			int j = s.size()-1;
			while(i <= j){
				if(!isvalid(s[i])){
					++i;
					continue;
				}
				if(!isvalid(s[j])){
					--j;
					continue;
				}
				if(s[i] == s[j]){
					++i;
					--j;
				}else{
					return false;
				}
			}
			return true;
		}
};

int main()
{
//	string s = "A B C C b a    ";
	string s = "1a2";
	Solution sol;
	cout << sol.isPalindrome(s) << endl;
	return 0;
}
